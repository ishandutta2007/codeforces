#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1e5 + 7, K = 501;
int n, m, k;
vector <int> g[N];
int c[K][K];
int cnt[K];
int col[N];

bool used[N];
int comp[N];
void dfs(int u, int cur) {
    used[u] = 1;
    comp[u] = cur;
    for (int v : g[u])  
        if (!used[v])
            dfs(v, cur);
}   

const int INF = 1e18;

vector <int> v[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < K; ++i)
        for (int j = 0; j < K; ++j)
            c[i][j] = INF;
    for (int i = 0; i < K; ++i)
        c[i][i] = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
        cin >> cnt[i];
    int ptr = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = ptr; j < ptr + cnt[i]; ++j)
            col[j] = i;
        ptr += cnt[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        --u; --v;
        c[col[u]][col[v]] = min(c[col[u]][col[v]], x);
        swap(u, v);
        c[col[u]][col[v]] = min(c[col[u]][col[v]], x);
        if (x == 0) {
            g[u].app(v);
            g[v].app(u);
        }
    }   
    int cur = 0;
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs(i, cur++);
    for (int i = 0; i < n; ++i)
        v[col[i]].app(i);
    for (int i = 0; i < k; ++i) {
        for (int j : v[i])
            if (comp[j] != comp[v[i][0]]) {
                cout << "No\n";
                exit(0);
            }   
    }   
    for (int t = 0; t < k; ++t)
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                c[i][j] = min(c[i][j], c[i][t] + c[t][j]);
    cout << "Yes\n";                    
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j)
            if (c[i][j] == INF)
                cout << "-1 ";
            else
                cout << c[i][j] << ' ';
        cout << '\n';
    }   
}