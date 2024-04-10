#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*
1
6 5
1 2 -1
1 3 1
4 2 7
6 3 0
2 5 -1
2 3 1
2 5 0
5 6 1
6 1 1
4 5 1
*/

vector<pii> g1[N];
vector<pii> g2[N];

int p[N], col[N];

void dfs1(int v, int par, int x) {
    p[v] = par;

    for(auto pr : g1[v]) {
        int u = pr.f, y = pr.s;

        if(u != par) {
            dfs1(u, v, y);
            if(y != -1) {
                g2[v].emplace_back(u, y);
                g2[u].emplace_back(v, y);
            }
        }
    }
}

bool ans = true;

void dfs2(int v, int cl) {
    col[v] = cl;
//    cout << "dfs2 " << v << ' ' << cl << ' ' << ans << endl;

    for(auto pr : g2[v]) {
        int u = pr.f, x = pr.s;

        if(col[u] == -1) {
//            cout << "go " << u << ' ' << col[u] << endl;
            dfs2(u, cl ^ x);
        } else if(col[u] != (cl ^ x)) {
            ans = false;
//            cout << "error " << v << ' ' << u << endl;
            return;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    ans = true;
    for(int i = 0; i < n; i++) {
        g1[i].erase(g1[i].begin(), g1[i].end());
        g2[i].erase(g2[i].begin(), g2[i].end());
        p[i] = col[i] = -1;
    }

    map<pii, int> mp;

    for(int i = 0; i < n - 1; i++) {
        int v, u, x;
        cin >> v >> u >> x;

        v--;
        u--;
        if(x != -1)
            mp[{v, u}] = mp[{u, v}] = x;
        if(x != -1)
            x = __builtin_popcount(x) % 2;

        g1[v].emplace_back(u, x);
        g1[u].emplace_back(v, x);
    }

    for(int i = 0; i < m; i++) {
        int v, u, x;
        cin >> v >> u >> x;

        v--;
        u--;

        g2[v].emplace_back(u, x);
        g2[u].emplace_back(v, x);
    }

    dfs1(0, 0, -1);

//    for(int i = 0; i < n; i++) {
//        cout << "i : " << i << endl;
//        for(auto pr : g2[i]) {
//            cout << i << ' ' << pr.f << ' ' << pr.s << endl;
//        }
//    }
//    cout << "sd" << endl;
//    return ;

    for(int i = 0; i < n; i++) {
        if(col[i] == -1) {
//            cout << i << endl;
            dfs2(i, 0);
        }
    }

    if(ans) {
        cout << "YES" << '\n';
        for(int i = 1; i < n; i++) {
            cout << i + 1 << ' ' << p[i] + 1 << ' ' << (mp.count({i, p[i]}) ? mp[{i, p[i]}] : col[i] != col[p[i]]) << '\n';
        }
    } else {
        cout << "NO" << '\n';
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}