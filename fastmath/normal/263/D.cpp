#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 1e5+7;
int n, m, k;
vector <int> g[N];

bool used[N];
int h[N];
int par[N];

int som = -1;

void dfs(int u) {
    used[u] = 1;
    bool leaf = 1;
    for (int v : g[u]) {
        if (!used[v]) {
            h[v] = h[u] + 1;
            par[v] = u;
            dfs(v);
            leaf = 0;
        }   
    }   
    if (leaf)
        som = u;
}

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    
    par[1] = 1;
    dfs(1);

    int u = som;
    assert(u != -1);

    int up = -1;
    for (int v : g[u]) {
        if (h[v] <= h[u] - k) {
            up = v;
        }   
    }   
    assert(up != -1);

    cout << h[u] - h[up] + 1 << endl;
    int t = u;
    while (t != up) {
        cout << t << ' ';
        t = par[t];
    }   
    cout << t << endl;
}