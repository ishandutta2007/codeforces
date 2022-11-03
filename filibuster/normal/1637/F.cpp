#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

vector<int> g[N];
int a[N];

pair<li, int> dfs1(int v, int par) {
    if(par != -1 && g[v].size() == 1) {
        return make_pair(li(a[v]), a[v]);
    }

    li res = 0;
    int mx = 0;
    for(int u : g[v]) {
        if(u != par) {
            auto pr = dfs1(u, v);
            res += pr.f;
            mx = max(mx, pr.s);
        }
    }

    res += max(mx, a[v]) - mx;
    return make_pair(res, max(mx, a[v]));
}

int mxv[N];

void dfs2(int v, int par) {
    mxv[v] = a[v];
    for(int u : g[v]) {
        if(u != par) {
            dfs2(u, v);
            mxv[v] = max(mxv[v], mxv[u]);
        }
    }
}

int dfs3(int v, int par) {
    if(g[v].size() == 1)
        return v;
    int mx = -1;
    for(int u : g[v]) {
        if(u != par && (mx == -1 || mxv[mx] < mxv[u])) {
            mx = u;
        }
    }

    return dfs3(mx, v);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > a[mx])
            mx = i;
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    int root = (n == 2 ? 0 : -1);
    for(int i = 0; i < n; i++) {
        if(g[i].size() > 1) {
            dfs2(i, -1);
            root = dfs3(i, -1);
            break;
        }
    }


//    for(int i = 0; i < n; i++) {
//        if(g[i].size() == 1 && (root == -1 || a[root] < a[i]))
//            root = i;
//    }

    cout << dfs1(root, -1).f + a[mx] << endl;

//    for(int i = 0; i < n; i++) {
//        if(g[i].size() == 1) {
//            cout << dfs1(i, -1).f + a[mx] << endl;
//        }
//    }
}