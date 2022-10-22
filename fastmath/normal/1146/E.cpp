#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N];
bool used[N << 3], p[N << 3], add[N << 3];
int mid(int l, int r) {
    return l + (r - l) / 2;
}
void push(int v) {
    if (used[v]) {
        used[v] = 0;
        for (int i = v * 2 + 1; i <= v * 2 + 2; ++i) {
            used[i] = 1;
            add[i] = 0;
            p[i] = p[v];
        }
    }
    else if (add[v]) {
        add[v] = 0;
        for (int i = v * 2 + 1; i <= v * 2 + 2; ++i) {
            if (used[i]) {
                p[i] ^= 1;
            }
            else {
                add[i] ^= 1;
            }
        }
    }
}
void upd(int v, int tl, int tr, int l, int r, bool x) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        used[v] = 1;
        p[v] = x;
        add[v] = 0;
        return;
    }
    int tm = mid(tl, tr);
    push(v);
    upd(v * 2 + 1, tl, tm, l, r, x); upd(v * 2 + 2, tm + 1, tr, l, r, x);
}
void upd(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return;
    if(l <= tl && tr <= r) {
        if (used[v]) p[v] ^= 1;
        else add[v] ^= 1;
        return;
    }
    int tm = mid(tl, tr);
    push(v);
    upd(v * 2 + 1, tl, tm, l, r); upd(v * 2 + 2, tm + 1, tr, l, r);
}
int ans[N << 1];
void print(int v, int tl, int tr) {
    if (tl == tr) {
        if (used[v]) ans[tl + N] = p[v];
        else ans[tl + N] = add[v];
        return;
    }
    int tm = mid(tl, tr);
    push(v);
    print(v * 2 + 1, tl, tm); print(v * 2 + 2, tm + 1, tr);
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) {
        char t;
        int x;
        cin >> t >> x;
        if (t == '<') {
            if (x > 0) {
                upd(0, -N, N, -x + 1, x - 1);
                upd(0, -N, N, -N, -x, 1);
                upd(0, -N, N, x, N, 0);
            }
            else {
                upd(0, -N, N, -N, x - 1, 1);
                upd(0, -N, N, -x + 1, N, 0);
            }
        }
        else {
            if (x < 0) {
                upd(0, -N, N, x + 1, -x - 1);
                upd(0, -N, N, -N, x, 0);
                upd(0, -N, N, -x, N, 1);
            }
            else {
                upd(0, -N, N, -N, -x-1, 0);
                upd(0, -N, N, x + 1, N, 1);
            }
        }
    }
    print(0, -N, N);
    for (int i = 0; i < n; ++i) {
        if (ans[a[i] + N]) cout << -a[i] << ' ';
        else cout << a[i] << ' ';
    }
    cout << '\n';
}