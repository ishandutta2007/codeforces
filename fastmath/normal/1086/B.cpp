#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const int MAXN = 1e5 + 7;

vector <int> g[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);

    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #else   
        
    #endif
    
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    
    int l = 0;
    for (int i = 0; i < n; ++i) {
        l += (g[i].size() == 1);
    }   

    cout << 2 * (double)(s) / l << '\n';

    return 0;
}