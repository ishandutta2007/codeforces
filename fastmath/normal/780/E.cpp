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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2e5 + 7;
int n, m, k;
vector <int> e;
bool used[N];
vector <int> g[N];
void dfs(int u) {
    used[u] = 1;
    e.app(u);
    for (int v : g[u]) 
        if (!used[v]) {
            dfs(v);
            e.app(u);
        }
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    int mx = (n * 2 + k - 1) / k;
    dfs(1);
    int ptr = 0;
    for (int i = 0; i < k; ++i) {
        if (ptr == e.size()) {
            cout << "1 1\n";
            continue;
        }   
        int add = min(mx, e.size() - ptr);
        cout << add << ' ';
        for (int j = 0; j < add; ++j) 
            cout << e[ptr + j] << ' ';
        cout << '\n';
        ptr += add;
    }   
}