#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 7;
const int INF = 1e18 + 7;
int d[N], c[N];
int tree[N << 2];
bool wp[N << 2];
int minc[N << 2], add[N << 2];
int pref[N];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = minc[v] = pref[tl];
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm); build(v * 2 + 2, tm + 1, tr);
    minc[v] = min(minc[v * 2 + 1], minc[v * 2 + 2]);
    tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}   
int mingap[N << 2];
int getl(int v, int tl, int tr, int x) {
    if (tl == tr) return tl;
    int tm = (tl + tr) >> 1;
    if (mingap[v * 2 + 1] <= x) return getl(v * 2 + 1, tl, tm, x);
    else return getl(v * 2 + 2, tm + 1, tr, x);
}   
void updgap(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        mingap[v] = x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    updgap(v * 2 + 1, tl, tm, l, r, x);
    updgap(v * 2 + 2, tm + 1, tr, l, r, x);
    mingap[v] = min(mingap[v * 2 + 1], mingap[v * 2 + 2]);
}   
void push(int v) {
    if (wp[v]) {
        wp[v] = 0;
        for (int i = v * 2 + 1; i <= v * 2 + 2; ++i) {
            wp[i] = 1;
            add[i] = add[v];
            tree[v] = minc[v] + add[v];
        }   
    }   
}   
void upd(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        wp[v] = 1;
        add[v] = x;
        tree[v] = minc[v] + add[v];
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v);
    upd(v * 2 + 1, tl, tm, l, r, x); 
    upd(v * 2 + 2, tm + 1, tr, l, r, x);
    tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}   
int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return INF;
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) >> 1;
    push(v);
    return min(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int n, a;
    cin >> n >> a;
    for (int i = 0; i < n; ++i) cin >> d[i] >> c[i];
    for (int i = 0; i < n; ++i) {
        c[i] = a - c[i];
    }   
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + c[i];
    }   
    build(0, 0, n - 1);
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i) {
            int ngap = d[i] - d[i - 1];
            ngap *= ngap;
            int p = getl(0, 0, n - 1, ngap);
            updgap(0, 0, n - 1, p, i - 1, ngap);
            upd(0, 0, n - 1, p, i - 1, ngap);
        }
        sum += c[i];
        ans = max(ans, sum - get(0, 0, n - 1, 0, i));
    }   
    cout << ans << '\n';
}