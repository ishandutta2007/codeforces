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
const int N = 4e5 + 7;
int n, m;
vector <int> g[N];
 
bool used[N];
vector <int> top;
void dfs(int u) {
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) 
            dfs(v);
    }
    top.app(u);
}   
int pos[N];

void dfs1(int u, bool used[N], vector <int> g[N]) {
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) {
            dfs1(v, used, g);
        }   
    }
}   
bool us[2][N];
vector <int> d[2][N];

int k = 0;
char ans[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v);
        d[0][u].app(v);
        d[1][v].app(u);
    }   
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            dfs(i);
        }   
    }
    for (int i = 0; i < n; ++i)
        pos[top[i]] = i;
    for (int u = 1; u <= n; ++u)
        for (int v : g[u])
            if (pos[u] < pos[v]) {
                cout << -1 << endl;
                exit(0);
            }

    for (int i = 1; i <= n; ++i) {
        if (!us[0][i] && !us[1][i]) {
            ans[i] = 'A';
            ++k;
        }   
        else {
            ans[i] = 'E';
        }   
        for (int j = 0; j < 2; ++j)
            if (!us[j][i])
                dfs1(i, us[j], d[j]);
    }
    cout << k << endl;
    for (int i = 1; i <= n; ++i)
        cout << ans[i];
    cout << endl;           
}