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
const int N = 2e5 + 7;
vector <int> g[N];
int par[N], h[N];

int w = 0;

bool used[N];
void dfs(int u, int p) {
    used[u] = 1;
    par[u] = p;
    for (int v : g[u]) {
        if (!used[v]) {
            h[v] = h[u] + 1;
            dfs(v, u);
        }
        else {
            if (h[u] - h[v] + 1 >= w) {
                cout << 2 << endl;
                cout << h[u] - h[v] + 1 << endl;
                int t = u;
                while (1) {
                    cout << t << ' ';
                    if (t == v)
                        break;
                    t = par[t];
                }   
                cout << endl;
                exit(0);
            }   
        }   
    }   
}   
vector <int> r[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    while (w * w < n)
        ++w;
    dfs(1, 1);
    cout << 1 << endl;
    vector <int> ans;
    for (int i = 1; i <= n; ++i) 
        r[h[i] % (w - 1)].app(i);
    for (int i = 0; i < N; ++i)
        if (r[i].size() >= w) {
            for (int j = 0; j < w; ++j)
                cout << r[i][j] << ' ';
            cout << endl;
            exit(0);
        }   
}