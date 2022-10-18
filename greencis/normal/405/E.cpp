#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

struct Edge {
    int a, b;
    bool used;
    inline int go(int from) {
        return from == a ? b : a;
    }
} e[100100];

vector<int> g[100100];
int ptr[100100];
bool usedVer[100100];
vector<tuple<int, int, int>> ans;

int dfs(int v, int prevEdge = -1) {
    usedVer[v] = true;
    int last = -1;
    for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
        int ed = g[v][ptr[v]];
        if (e[ed].used)
            continue;
        e[ed].used = true;
        int to = e[ed].go(v);
        int result = dfs(to, ed);
        if (result != -1) {
            if (last == -1)
                last = result;
            else {
                ans.emplace_back(e[last].go(v), v, e[result].go(v));
                last = -1;
            }
        }
    }
    if (prevEdge != -1) {
        if (last == -1)
            last = prevEdge;
        else {
            ans.emplace_back(e[last].go(v), v, e[prevEdge].go(v));
            last = -1;
        }
    }
    return last;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[i] = {x, y};
        g[x].push_back(i);
        g[y].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        if (!usedVer[i]) {
            if (dfs(i) != -1) {
                cout << "No solution\n";
                return 0;
            }
        }
    }
    for (auto [x, y, z] : ans) {
        cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
    }
}