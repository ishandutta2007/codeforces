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
const int N = 1e5 + 7;
map <int, int> ans;
vector <int> g[N];
map <ii, int> d;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
        d[mp(u, v)] = d[mp(v, u)] = i;
    }   
    int mx = 1;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() > g[mx].size()) {
            mx = i;
        }   
    }   
    int ptr = 0;
    for (int i = 0; i < min(3ll, (int)g[mx].size()); ++i) {
        int v = g[mx][i];
        ans[d[mp(mx, v)]] = ptr++;
    }   
    for (int i = 0; i < n - 1; ++i) {
        if (ans.find(i) != ans.end()) {
            cout << ans[i] << endl;
        }   
        else {
            cout << ptr++ << endl;
        }   
    }   
}