#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 7;
int n, m;
int l[N], r[N], x[N];
int tree[N << 2];
void push(int v) {
    if (tree[v] != -1) {
        tree[v * 2 + 1] = tree[v * 2 + 2] = tree[v];
        tree[v] = -1;
    }   
}   
void upd(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        tree[v] = x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v);
    upd(v * 2 + 1, tl, tm, l, r, x); upd(v * 2 + 2, tm + 1, tr, l, r, x);
}   
void print(int v, int tl, int tr) {
    if (tl == tr) {
        cout << tree[v] + 1 << ' ';
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v);
    print(v * 2 + 1, tl, tm); print(v * 2 + 2, tm + 1, tr);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < (N << 2); ++i) tree[i] = -1;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> x[i];
        --l[i]; --r[i]; --x[i];
    }   
    for (int i = m - 1; i >= 0; --i) {
        upd(0, 0, n - 1, l[i], x[i] - 1, x[i]);
        upd(0, 0, n - 1, x[i] + 1, r[i], x[i]);
    }   
    print(0, 0, n - 1);    
    cout << '\n';
}