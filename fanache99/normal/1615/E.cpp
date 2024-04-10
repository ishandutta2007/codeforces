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

const int MAXN = 200000;
const int INF = 1 << 28;

// (n - r - b) * (r - b)
//r * (n - r) - b * (n - b)

vector<int> g[1 + MAXN];
int cnt = 0;
int start[1 + MAXN], finish[1 + MAXN];
int depth[1 + MAXN], dad[1 + MAXN];
int tree[1 + 4 * MAXN], lazy[1 + 4 * MAXN];
int n, leaves = 0;

void propagate(int node) {
    if (lazy[node] != 0) {
        tree[2 * node] += lazy[node];
        tree[2 * node + 1] += lazy[node];
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
        lazy[node] = 0;
    }
}

void change(int node, int left, int right, int where, int val) {
    if (left == right) {
        assert(left == where);
        tree[node] = val;
        lazy[node] = 0;
        return;
    }
    propagate(node);
    int middle = (left + right) / 2;
    if (where <= middle) {
        change(2 * node, left, middle, where, val);
    } else {
        change(2 * node + 1, middle + 1, right, where, val);
    }
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int left, int right, int from, int to, int add) {
    if (from <= left && right <= to) {
        lazy[node] += add;
        tree[node] += add;
        return;
    }
    propagate(node);
    int middle = (left + right) / 2;
    if (from <= middle) {
        update(2 * node, left, middle, from, to, add);
    }
    if (middle + 1 <= to) {
        update(2 * node + 1, middle + 1, right, from, to, add);
    }
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int left, int right) {
    if (left == right) {
        return left;
    }
    propagate(node);
    int middle = (left + right) / 2;
    if (tree[2 * node] == tree[node]) {
        return query(2 * node, left, middle);
    } else {
        return query(2 * node + 1, middle + 1, right);
    }
}

int who[1 + MAXN];

void DFS(int node, int father) {
    start[node] = ++cnt;
    who[cnt] = node;
    depth[node] = depth[father] + 1;
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
            dad[son] = node;
        }
    }
    finish[node] = cnt;
    if (g[node].size() == 1 && node != 1) {
        leaves++;
        change(1, 1, n, start[node], depth[node]);
    }
}

bool out[1 + MAXN];

void solve(int n, int k) {
    long long ans = -1LL * (n / 2) * (n - n / 2);
    int t = n;
    for (int r = 1; r <= k; r++) {
        if (tree[1] > 0) {
            t -= tree[1];
            int x = who[query(1, 1, n)];
            while (x > 0 && !out[x]) {
                update(1, 1, n, start[x], finish[x], -1);
                out[x] = true;
                x = dad[x];
            }
        }
        int b = min(t, n / 2);
        ans = max(ans, 1LL * r * (n - r) - 1LL * b * (n - b));
    }
    cout << ans << "\n";
}

int main() {
    timeBegin();
    //  ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int k;
    cin >> n >> k;
    for (int i = 1; i <= 4 * n; i++) {
        tree[i] = -INF;
        lazy[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    solve(n, k);
    return 0;
}