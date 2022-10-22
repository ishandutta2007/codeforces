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

const int N = 1e6 + 7;
vector <int> g[N];

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

    vector <int> w(n+1);
    vector <ii> ord;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        ord.app(mp(w[i], i));
    }
    

    sort(all(ord));
    vector <int> ans;
    vector <int> c(n + 1);
    for (auto e : ord) {
        int u = e.s;
        ans.app(u);
        vector <int> a = {0, n + 1};
        for (int v : g[u]) {
            if (c[v])
                a.app(c[v]);                                          
        }   
        sort(all(a));
        for (int i = 0; i + 1 < a.size(); ++i) {
            if (a[i] + 1 < a[i + 1]) {
                c[u] = a[i] + 1;
                break;
            }   
        }   
        if (c[u] != w[u]) {
            cout << -1 << endl;
            exit(0);
        }   
    }   

    for (auto e : ans)
        cout << e << ' ';
    cout << endl;
}