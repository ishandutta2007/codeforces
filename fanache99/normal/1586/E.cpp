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

const int MAXN = 300000;
const int MAXQ = 300000;

vector<int> g[1 + MAXN], adj[1 + MAXN];
int a[1 + MAXQ], b[1 + MAXQ];
int other[1 + MAXQ][2];
vector<int> ans[1 + MAXQ];
bool seen[1 + MAXN];

void matchOne(int x, int y, int node) {
    if (a[x] == node) {
        other[x][0] = y;
    } else {
        assert(b[x] == node);
        other[x][1] = y;
    }
    if (a[y] == node) {
        other[y][0] = x;
    } else {
        assert(b[y] == node);
        other[y][1] = x;
    }
}

void matchAdj(int x) {
    assert(adj[x].size() % 2 == 0);
    for (int i = 0; i < adj[x].size(); i += 2) {
        matchOne(adj[x][i], adj[x][i + 1], x);
    }
}

vector<int> st, st2;
bool onSt[1 + MAXN];
int cnt;
int last[1 + MAXN];
bool found;

void dfs(int node) {
    st2.push_back(node);
    last[node] = cnt;
    if (onSt[node]) {
        found = true;
        return;
    }
    for (auto it : g[node]) {
        if (last[it] != cnt) {
            dfs(it);
            if (found) {
                return;
            }
        }
    }
    st2.pop_back();
}

void solve(int edge, int node) {
    st2.clear();
    cnt++;
    found = false;
    dfs(node);
    assert(!st2.empty() && onSt[st2.back()] && st2[0] == node);
    ans[edge].push_back(st.back());
    while (st.back() != st2.back()) {
        onSt[st.back()] = false;
        st.pop_back();
        ans[edge].push_back(st.back());
    }
    st2.pop_back();
    reverse(st2.begin(), st2.end());
    for (auto it : st2) {
        onSt[it] = true;
        st.push_back(it);
        ans[edge].push_back(it);
    }
    assert(st.back() == node);
}

void DFS(int edge, int o) {
    if (!ans[edge].empty()) {
        return;
    }
    int node = (o == 1 ? b[edge] : a[edge]);
    solve(edge, node);
    if (o == 2) {
        reverse(ans[edge].begin(), ans[edge].end());
    }
    assert(ans[edge][0] == a[edge] && ans[edge].back() == b[edge]);
    int newEdge = (o == 1 ? other[edge][1] : other[edge][0]);
    int newO = (node == a[newEdge] ? 1 : 2);
    DFS(newEdge, newO);
}

void orient(int n, int q) {
    for (int i = 1; i <= q; i++) {
        if (ans[i].empty()) {
            st.clear();
            for (int j = 1; j <= n; j++) {
                onSt[j] = false;
                last[j] = 0;
                cnt = 0;
            }
            st.push_back(a[i]);
            onSt[a[i]] = true;
            DFS(i, 1);
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> a[i] >> b[i];
        adj[a[i]].push_back(i);
        adj[b[i]].push_back(i);
    }
    int odd = 0;
    for (int i = 1; i <= n; i++) {
        odd += (adj[i].size() % 2 == 1);
    }
    if (odd != 0) {
        assert(odd % 2 == 0);
        cout << "NO\n" << odd / 2 << "\n";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            matchAdj(i);
        }
        orient(n, q);
        for (int i = 1; i <= q; i++) {
            cout << ans[i].size() << "\n";
            for (auto it : ans[i]) {
                cout << it << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}