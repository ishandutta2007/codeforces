#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 1e5 + 13;
const int B = 350;
const int A = 26;
const int LOGN = 20;

vector<pii> g[N];
int tin[N], tout[N];
int p[N][LOGN];
int T = 1;
int ans[N];
int s[N];

void dfs1(int v, int par) {
    tin[v] = ++T;

    p[v][0] = par;
    for(int i = 1; i < LOGN; i++) {
        p[v][i] = p[p[v][i - 1]][i - 1];
    }

//    cout << "dfs " << v << endl;
//    for(int i = 0; i < LOGN; i++) {
//        cout << p[v][i] << ' ';
//    }
//    cout << endl;

    for(auto ed : g[v]) {
        if(tin[ed.f] == 0)
            dfs1(ed.f, v);
    }

    tout[v] = ++T;
}

bool is_anc(int pr, int v) {
    return (tin[pr] <= tin[v] && tout[v] <= tout[pr]);
}

int lca(int v, int u) {
    if(is_anc(v, u))
        return v;

    if(is_anc(u, v))
        return u;

    for(int k = LOGN - 1; k >= 0; k--) {
//        cout << "lca " << k << ' ' << v << ' ' << u << endl;
        if(!is_anc(p[v][k], u))
            v = p[v][k];
    }


    return p[v][0];
}

int dfs2(int v, int ind) {
    int sum = 0;
    for(auto ed : g[v]) {
        if(p[v][0] != ed.f) {
            ans[ed.s] = dfs2(ed.f, ed.s);
            sum += ans[ed.s];
        }

    }
//    cout << v << ' ' << sum << ' ' << s[v] << endl;
    return sum + s[v];
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].emplace_back(u, i);
        g[u].emplace_back(v, i);
    }

    dfs1(0, 0);

    int k;
    cin >> k;

    for(int i = 0; i < k; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        if(is_anc(v, u))
            swap(v, u);

        if(is_anc(u, v)) {
            s[u]--;
            s[v]++;
        } else {
            int w = lca(v, u);
//            cout << v << ' '<< w << ' ' << u << endl;
            s[v]++;
            s[u]++;
            s[w]--;
            s[w]--;
        }
    }

//    for(int i = 0; i < n; i++){
//        cout << s[i] << ' ';
//    }
//    cout << endl;

    dfs2(0, n);

    for(int i = 0; i < n - 1; i++) {
        cout << ans[i] << ' ';
    }
}