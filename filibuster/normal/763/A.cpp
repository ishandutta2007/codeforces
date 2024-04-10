#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 350;

vector<int> g[N];
int c[N];

bool dfs(int v, int p) {
    bool res = true;
    for(auto u : g[v]) {
        if(u == p)
            continue;
        res = res && c[v] == c[u];
        res = res && dfs(u, v);
    }

    return res;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int root = -1, rt = -1;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(auto j : g[i])
            if(c[i] != c[j])
                cnt++;

        if(cnt > 1) {
            root = i;
        } else if(cnt == 1) {
            rt = i;
        }
    }

    if(rt == -1) {
        cout << "YES" << endl << 1 << endl;
        return 0;
    }

    if(root == -1)
        root = rt;

    for(auto v : g[root])
        if(!dfs(v, root)) {
            cout << "NO" << endl;
            return 0;
        }

    cout << "YES" << endl;
    cout << root + 1 << endl;
}