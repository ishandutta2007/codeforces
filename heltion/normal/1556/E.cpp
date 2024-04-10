#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
constexpr int maxn = 100000 + 1;
int a[maxn + 1], b[maxn + 1];
struct Node{
    LL lmx, rmx, mx, lmi, rmi, mi, sum;
}t[maxn << 2];
Node operator * (const Node& p, const Node& q){
    return {
        max(p.lmx, p.sum + q.lmx),
        max(q.rmx, q.sum + p.rmx),
        max({p.mx, q.mx, p.rmx + q.lmx}),
        min(p.lmi, p.sum + q.lmi),
        min(q.rmi, q.sum + p.rmi),
        min({p.mi, q.mi, p.rmi + q.lmi}),
        p.sum + q.sum
    };
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        LL x = b[tm] - a[tm];
        t[v] = {
            max(x, 0LL), max(x, 0LL), max(x, 0LL),
            min(x, 0LL), min(x, 0LL), min(x, 0LL),
            x
        };
    }
    else {
        build(ls, tl, tm);
        build(rs, tm + 1, tr);
        t[v] = t[ls] * t[rs];
    }
}
Node query(int v, int tl, int tr, int L, int R) {
    if (tl >= L and tr <= R) return t[v];
    if (R <= tm) return query(ls, tl, tm, L, R);
    if (L > tm) return query(rs, tm + 1, tr, L, R);
    return query(ls, tl, tm, L, R) * query(rs, tm + 1, tr, L, R);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i += 1)
        cin >> a[i];
    for (int i = 1; i <= n; i += 1) 
        cin >> b[i];
    build(1, 1, n);
    for (; q; q -= 1) {
        int l, r;
        cin >> l >> r;
        auto x = query(1, 1, n, l, r);
        if (x.sum == 0 and x.lmi == 0)
            cout << max(x.mx, -x.mi) << "\n";
        else cout << "-1\n";
    }
    return 0;
}