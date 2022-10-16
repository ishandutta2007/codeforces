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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

    inline InputReader &operator>>(int &n) {
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

const int MAXN = 400000;
const int MAXLOG = 20;

vector<int> g[1 + MAXN];
int dad[1 + MAXN][1 + MAXLOG];
int depth[1 + MAXN];

void DFS(int node, int father) {
    depth[node] = depth[father] + 1;
    dad[node][0] = father;
    for (int i = 1; i <= MAXLOG; i++) {
        dad[node][i] = dad[dad[node][i - 1]][i - 1];
    }
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
        }
    }
}

int raise(int node, int delta) {
    for (int i = 0; i <= MAXLOG; i++) {
        if (delta & (1 << i)) {
            node = dad[node][i];
        }
    }
    return node;
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    b = raise(b, depth[b] - depth[a]);
    for (int i = MAXLOG; i >= 0; i--) {
        if (dad[a][i] != dad[b][i]) {
            a = dad[a][i];
            b = dad[b][i];
        }
    }
    if (a != b) {
        a = dad[a][0];
        b = dad[b][0];
    }
    assert(a == b);
    return a;
}

int go(int a, int b, int c, int k) {
    if (k <= depth[a] - depth[c]) {
        return raise(a, k);
    } else {
        return raise(b, depth[b] - depth[c] - (k - (depth[a] - depth[c])));
    }
}

int root[1 + MAXN], d[1 + MAXN];

int findRoot(int node) {
    if (root[node] == node) {
        return node;
    }
    return root[node] = findRoot(root[node]);
}

bool query(int a, int b, int k) {
    int c = lca(a, b);
    if (depth[a] + depth[b] - 2 * depth[c] <= 2 * k) {
        return true;
    }
    int a0 = go(a, b, c, k), b0 = go(b, a, c, k);
    return findRoot(a0) == findRoot(b0);
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, k, r;
    cin >> n >> k >> r;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(i + n);
        g[i + n].push_back(a);
        g[b].push_back(i + n);
        g[i + n].push_back(b);
    }
    n = n + n - 1;
    DFS(1, 0);
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        d[i] = 2 * n;
    }
    queue<int> queue;
    for (int i = 1; i <= r; i++) {
        int x;
        cin >> x;
        queue.push(x);
        d[x] = 0;
    }
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        if (d[node] >= k) {
            continue;
        }
        for (auto it : g[node]) {
            root[findRoot(it)] = findRoot(node);
            if (d[it] > d[node] + 1) {
                d[it] = d[node] + 1;
                queue.push(it);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        cout << (query(a, b, k) ? "YES" : "NO") << "\n";
    }
    return 0;
}