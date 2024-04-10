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
    inline InputReader &operator >>(int &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 500000;
const int MAXQ = 500000;
const long long INF = 1000000000000000000LL;

struct Query {
    int l;
    int r;
    int id;
};

vector<pair<int, int> > g[1 + MAXN];
int from[1 + MAXN], to[1 + MAXN];
long long answer[1 + MAXQ];
vector<Query> queries[1 + MAXN];
long long tree[1 + 4 * MAXN], lazy[1 + 4 * MAXN];

void build(int node, int left, int right) {
    tree[node] = INF;
    lazy[node] = 0;
    if (left == right) {
        return;
    }
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    build(leftSon, left, middle);
    build(rightSon, middle + 1, right);
}

void propagate(int node) {
    if (lazy[node] != 0) {
        int leftSon = 2 * node, rightSon = 2 * node + 1;
        lazy[leftSon] += lazy[node];
        tree[leftSon] += lazy[node];
        lazy[rightSon] += lazy[node];
        tree[rightSon] += lazy[node];
        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int from, int to, long long add) {
    if (from <= left && right <= to) {
        lazy[node] += add;
        tree[node] += add;
        return;
    }
    propagate(node);
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    if (from <= middle) {
        update(leftSon, left, middle, from, to, add);
    }
    if (middle + 1 <= to) {
        update(rightSon, middle + 1, right, from, to, add);
    }
    tree[node] = min(tree[leftSon], tree[rightSon]);
}

long long query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        return tree[node];
    }
    propagate(node);
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    long long answer = INF;
    if (from <= middle) {
        answer = min(answer, query(leftSon, left, middle, from, to));
    }
    if (middle + 1 <= to) {
        answer = min(answer, query(rightSon, middle + 1, right, from, to));
    }
    tree[node] = min(tree[leftSon], tree[rightSon]);
    return answer;
}

void DFS(int node, int n, long long l) {
    if (g[node].empty()) {
        from[node] = to[node] = node;
        update(1, 1, n, node, node, -INF + l);
        return;
    }
    from[node] = n;
    to[node] = 0;
    for (auto it : g[node]) {
        int son = it.first, w = it.second;
        DFS(son, n, l + w);
        from[node] = min(from[node], from[son]);
        to[node] = max(to[node], to[son]);
    }
}

void solve(int node, int n) {
    for (auto q : queries[node]) {
        answer[q.id] = query(1, 1, n, q.l, q.r);
    }
    for (auto it : g[node]) {
        int son = it.first, w = it.second;
        update(1, 1, n, 1, n, w);
        update(1, 1, n, from[son], to[son], -2 * w);
        solve(son, n);
        update(1, 1, n, 1, n, -w);
        update(1, 1, n, from[son], to[son], 2 * w);
    }
}

int main() {
    timeBegin();
    InputReader cin;
    //ofstream cout("abbreviation.out");
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int p, w;
        cin >> p >> w;
        g[p].push_back({i, w});
    }
    build(1, 1, n);
    DFS(1, n, 0);
    for (int i = 1; i <= q; i++) {
        int node, l, r;
        cin >> node >> l >> r;
        queries[node].push_back({l, r, i});
    }
    solve(1, n);
    for (int i = 1; i <= q; i++) {
        cout << answer[i] << "\n";
    }
    //timeDuration();
    return 0;
}