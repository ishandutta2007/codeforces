#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define f first
#define s second
#define bp __builtin_popcount
#define all(a) a.begin(),a.end()
#define ll long long
#define mp make_pair
const int N = 2e5 + 7, INF = 1e18;
int n, m, p;
int a[N], ca[N], b[N], cb[N], x[N], y[N], z[N];

vector <ii> vb;
int mx[N << 2], prop[N << 2];
void relax(int v) {
    mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
}   
void gap(int v, int x) {
    mx[v] += x;
    prop[v] += x;
}   
void push(int v) {
    gap(v * 2 + 1, prop[v]);
    gap(v * 2 + 2, prop[v]);
    prop[v] = 0;
}   
void build(int v, int l, int r) {
    if (l == r) {
        int i = vb[l].s;
        mx[v] = -cb[i];
        return;
    }          
    int m = (l + r) >> 1;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m + 1, r);
    relax(v);
}   
void upd(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) 
        return;
    if (l <= tl && tr <= r) {
        gap(v, x);
        return;
    }   
    push(v);
    int tm = (tl + tr) >> 1;
    upd(v * 2 + 1, tl, tm, l, r, x);
    upd(v * 2 + 2, tm + 1, tr, l, r, x);
    relax(v);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) 
        cin >> a[i] >> ca[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i] >> cb[i];
    for (int i = 0; i < p; ++i)
        cin >> x[i] >> y[i] >> z[i];
    vector <ii> va;
    for (int i = 0; i < n; ++i)
        va.app(mp(a[i], i));
    sort(all(va));

    for (int i = 0; i < m; ++i)
        vb.app(mp(b[i], i));
    sort(all(vb));

    vector <ii> vm;
    for (int i = 0; i < p; ++i)
        vm.app(mp(x[i], i));
    sort(all(vm));

    build(0, 0, m - 1);

    int ptr = 0;
    int ans = -INF;
    for (auto e : va) {
        while (ptr < vm.size() && vm[ptr].f < e.f) {
            
            int i = vm[ptr].s;
            auto t = lower_bound(all(vb), mp(y[i] + 1, 0ll));
            int l = t - vb.begin();
            upd(0, 0, m - 1, l, m - 1, z[i]);
            
            ++ptr;
        }
        ans = max(ans, mx[0] - ca[e.s]);
    }   

    cout << ans << endl;
}