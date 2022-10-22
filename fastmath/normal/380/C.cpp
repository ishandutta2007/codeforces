#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
int n;
string s;
struct Vert {
    int ans, l, r;
};
Vert tree[N << 2];
Vert merge(Vert l, Vert r) {
    Vert ans;
    ans.ans = l.ans + r.ans + min(l.l, r.r) * 2;
    ans.l = l.l + r.l - min(l.l, r.r);
    ans.r = l.r + r.r - min(l.l, r.r);
    return ans;
}   
void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].ans = 0;
        tree[v].l = s[tl] == '(';
        tree[v].r = s[tl] == ')';
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm); build(v * 2 + 2, tm + 1, tr);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}   
Vert get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return {0, 0, 0};
    if (l <= tl && tr <= r) {
        return tree[v];
    }
    int tm = (tl + tr) >> 1;
    return merge(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> s;
    int n = s.size();
    build(0, 0, n - 1);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        cout << get(0, 0, n - 1, l, r).ans << '\n';
    }   
}