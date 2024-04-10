#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2007;
int get(int u, int v) {
    cout << "? " << u << ' ' << v << endl;
    int ans;
    cin >> ans;
    return ans;
}   
void print(int ans) {
    cout << "! " << ans << endl;
    exit(0);
}   
vector <int> g[N];
void dfs(int u, int p, bool used[N]) {
    used[u] = 1;
    for (int v : g[u])
        if (v != p)
            dfs(v, u, used);
}
bool del[N], inl[N], inr[N];
signed main() {
    int n;
    cin >> n;
    vector <ii> e;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        e.app(mp(u, v));
    }   
    while (1) {
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        for (auto t : e)
            if (!del[t.f] && !del[t.s]) {
                g[t.f].app(t.s);
                g[t.s].app(t.f);
            }   
        vector <int> a;
        for (int i = 1; i <= n; ++i) {
            if (!del[i]) {
                a.app(i);
            }   
        }

        #ifdef HOME
        cout << "while " << endl;
        for (int e : a)
            cout << e << ' ';
        cout << endl;
        #endif
        if (a.size() == 1) {
            print(a[0]);
        }   
        if (a.size() == 2) {
            print(get(a[0], a[1]));
        }
        for (int u : a) {
            if (g[u].size() > 1) {
                int l = g[u][0], r = g[u][1];

                memset(inl, 0, sizeof inl);
                memset(inr, 0, sizeof inr);
                dfs(l, u, inl); dfs(r, u, inr);
                int t = get(l, r);

                if (t == u) {
                    for (int e : a)
                        if (inl[e] || inr[e])
                            del[e] = 1;
                }   
                else if (t == l) {
                    for (int e : a)
                        if (!inl[e])
                            del[e] = 1;
                }   
                else if (t == r) {
                    for (int e : a)
                        if (!inr[e])
                            del[e] = 1;
                }

                break;   
            }   
        }       
    }   
}