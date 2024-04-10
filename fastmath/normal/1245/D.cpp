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

const int N = 2007;
int par[N];
int root(int u) {
    if (par[u] == u)
        return u;
    else
        return par[u] = root(par[u]);
}   

struct Edge {
    int u, v, c;
};
bool comp(Edge a, Edge b) {
    return a.c < b.c;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <ii> p(n);
    vector <int> c(n), k(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].f >> p[i].s;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i)
        cin >> k[i];
    for (int i = 0; i <= n; ++i)
        par[i] = i;
    vector <Edge> a;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            a.app({i, j, (k[i] + k[j]) * (abs(p[i].f - p[j].f) + abs(p[i].s - p[j].s))});
    for (int i = 0; i < n; ++i)
        a.app({i, n, c[i]});
    sort(all(a), comp);
    int ans = 0;
    vector <int> a1;
    vector <ii> a2;
    for (auto e : a) {
        int u = root(e.u), v = root(e.v);
        if (u != v) {
            par[u] = v;
            ans += e.c;
            if (e.v == n) {
                a1.app(e.u);
            }   
            else {
                a2.app(mp(e.u, e.v));
            }   
        }   
    }   
    cout << ans << endl;
    cout << a1.size() << endl;
    for (auto e : a1)
        cout << e + 1 << ' ';
    cout << endl;
    cout << a2.size() << endl;
    for (auto e : a2)
        cout << e.f + 1 << ' ' << e.s + 1 << endl;
}