#include<bits/stdc++.h>
using namespace std;
#define int long long
#define app push_back
const int N = 1e5 + 7;
vector <int> g[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 2) {
            cout << "NO\n";
            exit(0);
        }   
    }   
    cout << "YES\n";
}