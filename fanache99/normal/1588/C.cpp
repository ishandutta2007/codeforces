#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    template<typename T>
    inline InputReader &operator>>(T &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }

private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];

    inline void advance() {
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 300000;
const long long INF = 1e18;

long long v[1 + MAXN], dp[1 + MAXN + 1];
long long tree[2][1 + 4 * MAXN], lazy[2][1 + 4 * MAXN];

void propagate(int node, long long tree[], long long lazy[]) {
    if (lazy[node] != 0) {
        lazy[2 * node] += lazy[node];
        tree[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
        tree[2 * node + 1] += lazy[node];
        lazy[node] = 0;
    }
}

void change(int node, int left, int right, int pos, long long val, long long tree[], long long lazy[]) {
    if (left == right) {
        tree[node] = val;
        return;
    }
    propagate(node, tree, lazy);
    int middle = (left + right) / 2;
    if (pos <= middle) {
        change(2 * node, left, middle, pos, val, tree, lazy);
    } else {
        change(2 * node + 1, middle + 1, right, pos, val, tree, lazy);
    }
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int left, int right, int from, int to, long long add, long long tree[], long long lazy[]) {
    if (from <= left && right <= to) {
        tree[node] += add;
        lazy[node] += add;
        return;
    }
    propagate(node, tree, lazy);
    int middle = (left + right) / 2;
    if (from <= middle) {
        update(2 * node, left, middle, from, to, add, tree, lazy);
    }
    if (middle + 1 <= to) {
        update(2 * node + 1, middle + 1, right, from, to, add, tree, lazy);
    }
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

void query(int node, int left, int right, int from, int to, long long tree[], long long lazy[], long long &mn, long long &pos) {
    if (left == right) {
        if (tree[node] <= 0) {
            mn = tree[node];
            pos = left;
        } else {
            mn = pos = INF;
        }
        return;
    }
    propagate(node, tree, lazy);
    int middle = (left + right) / 2;
    if (from <= middle && tree[2 * node] <= 0) {
        query(2 * node, left, middle, from, to, tree, lazy, mn, pos);
    }
    if (pos == INF && middle + 1 <= to) {
        query(2 * node + 1, middle + 1, right, from, to, tree, lazy, mn, pos);
    }
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        for (int i = 1; i <= 4 * n; i++) {
            tree[0][i] = tree[1][i] = INF;
            lazy[0][i] = lazy[1][i] = 0;
        }
        long long ans = 0;
        dp[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            change(1, 1, n, i, 0, tree[i % 2], lazy[i % 2]);
            update(1, 1, n, i, n, v[i], tree[i % 2], lazy[i % 2]);
            update(1, 1, n, i, n, -v[i], tree[(i + 1) % 2], lazy[(i + 1) % 2]);
            long long mn[2] = {INF, INF}, pos[2] = {INF, INF};
            query(1, 1, n, i, n, tree[i % 2], lazy[i % 2], mn[i % 2], pos[i % 2]);
            query(1, 1, n, i, n, tree[(i + 1) % 2], lazy[(i + 1) % 2], mn[(i + 1) % 2], pos[(i + 1) % 2]);
            long long nxt, fstMn;
            if (pos[0] < pos[1]) {
                nxt = pos[0];
                fstMn = mn[0];
            } else {
                nxt = pos[1];
                fstMn = mn[1];
            }
            if (fstMn < 0 || nxt > n) {
                dp[i] = INF;
            } else {
                dp[i] = (dp[nxt + 1] == INF ? 0 : dp[nxt + 1]) + 1;
                ans += dp[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}