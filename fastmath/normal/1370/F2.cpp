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

const int INF = 1e9+7;

void dfs(int u, int p, vector <vector <int> > &g, vector <int> &h, vector <int> &cnt) {
    cnt[u] = 1;
    for (int v : g[u]) {
        if (v != p) {
            h[v] = h[u] + 1;
            dfs(v, u, g, h, cnt);
            cnt[u] += cnt[v];
        }   
    }   
}   
void go(int u, int p, vector <vector <int> > &g, vector <bool> &used) {
    used[u] = 1;
    for (int v : g[u]) {
        if (v != p) {
            go(v, u, g, used);
        }   
    }
}   

int get(int n) {
    int cur = 1;
    int ans = 0;
    while (cur < n) {
        cur <<= 1;
        ++ans;
    }
    return ans;
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
        vector <int> h(n + 1), cnt(n+1);
        dfs(1, 1, g, h, cnt);
        
        cout << "? " << n << endl;
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << endl;

        int x, d;
        cin >> x >> d;

        for (auto &e : h)
            e = 0;
        dfs(x, x, g, h, cnt);
        int u;
        int lh = (d+1)/2;
        int rh = d;
        int len = rh - lh + 1;
        if (get(len) <= 8) {
            int l = lh;
            int r = rh;
            while (l < r) {
                int m = (l + r) >> 1;
                vector <int> t;
                for (int i = 1; i <= n; ++i) {
                    if (m+1 <= h[i] && h[i] <= r) {
                        t.app(i);
                    }   
                }

                int x1, d1;

                if (t.size()) {
                    cout << "? " << t.size() << endl;
                    for (auto e : t)
                        cout << e << ' ';
                    cout << endl;
                    cin >> x1 >> d1;
                }
                else {
                    x1 = -1;
                    d1 = INF;
                }   

                if (d1 == d) {
                    l = m + 1;
                }   
                else {
                    r = m;
                }   
            }   
            vector <int> t;
            for (int i = 1; i <= n; ++i)
                if (h[i] == l)
                    t.app(i);
            int x1, d1;
            cout << "? " << t.size() << endl;
            for (auto e : t)
                cout << e << ' ';
            cout << endl;
            cin >> x1 >> d1;
            u = x1;
        }   
        else {
            int big = -1;
            for (int v : g[x]) {
                if (big == -1 || cnt[v] > cnt[big]) {
                    big = v;
                }   
            }   

            vector <bool> used(n+1);
            go(big, x, g, used);

            vector <int> ord;
            for (int i = 1; i <= n; ++i)
                if (!used[i])
                    ord.app(i);
            auto comp = [&](int u, int v) {
                return h[u] < h[v];
            };
            sort(all(ord), comp);

            int l = 0, r = ord.size() - 1;
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
            u = ord[l];
        }

        for (auto &e : h)
            e = 0;
        dfs(u, u, g, h, cnt);

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