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

const int MAXN = 100000;
const long long INF = 1e18;

long long v[1 + MAXN];
long long ans[1 + MAXN];
long long tree[1 + 4 * MAXN];

int combine(int a, int b) {
    if (v[a] < v[b] || (v[a] == v[b] && a < b)) {
        return a;
    } else {
        return b;
    }
}

void build(int node, int left, int right) {
    if (left == right) {
        tree[node] = left;
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int left, int right, int where) {
    if (left == right) {
        v[left] = INF + 1;
        tree[node] = left;
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle) {
        update(2 * node, left, middle, where);
    } else {
        update(2 * node + 1, middle + 1, right, where);
    }
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int left, int right, int pos, long long lim) {
    if (pos < 1) {
        return 0;
    }
    if (left == right) {
        if (v[left] <= lim) {
            return left;
        } else {
            return 0;
        }
    }
    int middle = (left + right) / 2;
    if (v[tree[2 * node]] <= lim) {
        return query(2 * node, left, middle, pos, lim);
    } else if (middle + 1 <= pos) {
        return query(2 * node + 1, middle + 1, right, pos, lim);
    } else {
        return 0;
    }
}

int smallest(int node, int left, int right, int pos) {
    if (pos < 1) {
        return 0;
    }
    if (right <= pos) {
        return tree[node];
    }
    int middle = (left + right) / 2;
    int answer = smallest(2 * node, left, middle, pos);
    if (middle + 1 <= pos) {
        answer = combine(answer, smallest(2 * node + 1, middle + 1, right, pos));
    }
    return answer;
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    v[0] = INF;
    multiset<long long> ts;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        ts.insert(v[i]);
    }
    build(1, 1, n);
    queue<pair<long long, int> > q;
    int r = n;
    long long t = 0;
    while (r > 0) {
        if (q.empty()) {
            assert(!ts.empty());
            t = max(t, *ts.begin());
            int x = query(1, 1, n, n, t);
            q.push({t, x});
            ts.erase(ts.find(v[x]));
            update(1, 1, n, x);
        } else {
            int x = smallest(1, 1, n, q.back().second - 1);
            if (v[x] <= q.front().first + p) {
                assert(t <= v[x]);
                t = v[x];
                q.push({t, x});
                ts.erase(ts.find(v[x]));
                update(1, 1, n, x);
            } else {
                t = q.front().first + p;
                x = q.front().second;
                ans[x] = t;
                q.pop();
                r--;
                if (!q.empty()) {
                    q.front().first = t;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}