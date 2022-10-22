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

void dfs(int u, int p, vector <vector <int> > &g, vector <int> &h) {
    for (int v : g[u]) {
        if (v != p) {
            h[v] = h[u] + 1;
            dfs(v, u, g, h);
        }   
    }   
}   

signed main() {

    int t;
    cin >> t;

    while (t--) {
        
        int n;
        cin >> n;
        vector <vector <int> > g(n+1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].app(v); g[v].app(u);
        }   
        vector <int> h(n + 1);
        dfs(1, 1, g, h);
        
        vector <int> ord;
        for (int i = 1; i <= n; ++i)
            ord.app(i);
        auto comp = [&](int u, int v) {
            return h[u] < h[v];
        };
        sort(all(ord), comp);

        cout << "? " << n << endl;
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << endl;

        int x, d;
        cin >> x >> d;

        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            vector <int> t;
            for (int i = m + 1; i <= r; ++i)
                t.app(ord[i]);

            cout << "? " << t.size() << endl;
            for (auto e : t)
                cout << e << ' ';
            cout << endl;

            int x1, d1;
            cin >> x1 >> d1;
            if (d1 == d) {
                l = m + 1;
            }   
            else {
                r = m;
            }   
        }   

        int u = ord[l];
        for (auto &e : h)
            e = 0;
        dfs(u, u, g, h);

        vector <int> t;
        for (int v = 1; v <= n; ++v)
            if (h[v] == d)
                t.app(v);

        cout << "? " << t.size() << endl;
        for (auto e : t)
            cout << e << ' ';
        cout << endl;

        int x1, d1;
        cin >> x1 >> d1;

        cout << "! " << u << ' ' << x1 << endl;

        string res;
        cin >> res;
    }   
    
}