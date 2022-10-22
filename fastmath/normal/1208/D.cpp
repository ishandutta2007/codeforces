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
const int N = 2e5 + 7, INF = 1e18 + 7;
int n, a[N], mn[N << 2], add[N << 2];
void mem(int v, int x) {
    mn[v] += x; add[v] += x;
}
void push(int v) {
    mem(v * 2 + 1, add[v]);
    mem(v * 2 + 2, add[v]);
    add[v] = 0;
}   
void relax(int v) {
    mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
}
void build(int v, int l, int r) {
    if (l == r) { mn[v] = a[l]; return; }
    int m = (l + r) >> 1;
    build(v * 2 + 1, l, m); build(v * 2 + 2, m + 1, r);
    relax(v);
}
void upd(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) { mem(v, x); return; }
    int tm = (tl + tr) >> 1;
    push(v);
    upd(v * 2 + 1, tl, tm, l, r, x); upd(v * 2 + 2, tm + 1, tr, l, r, x);
    relax(v);
}
int get(int v, int l, int r) {
    if (l == r) return l;
    int m = (l + r) >> 1;
    push(v);
    if (mn[v * 2 + 2] == 0) return get(v * 2 + 2, m + 1, r);
    else return get(v * 2 + 1, l, m);
}
int ans[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    build(0, 0, n - 1);
    for (int i = 1; i <= n; ++i) {
        int p = get(0, 0, n - 1);
        ans[p] = i;
        upd(0, 0, n - 1, p, p, INF);
        upd(0, 0, n - 1, p + 1, n - 1, -i);
    }   
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}