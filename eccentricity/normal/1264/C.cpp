#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 500000;
LL power(LL a, LL r){
    LL res = 1;
    for(; r; r >>= 1, a = a * a % mod)
        if(r & 1) res = res * a % mod;
    return res;
}
LL p[maxn];
//En = 1 + pnE[n+1] + (1-p)En
//En = [pn (1-pn)  1] En+1
//E1   [    1       ] E1
//1    [           1] 1
//ER = 0
struct M{
    LL A, B, C;
    M operator * (const M &R){
        return {A * R.A % mod, (A * R.B + B) % mod, (A * R.C + C) % mod};
    }
}a[maxn], pro[maxn];
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
void build(int v, int tl, int tr){
    if(tl == tr) pro[v] = a[tm];
    else{
        build(ls, tl, tm);
        build(rs, tm + 1, tr);
        pro[v] = pro[ls] * pro[rs];
    }
}
M query(int v, int tl, int tr, int L, int R){
    if(tl >= L and tr <= R) return pro[v];
    M res = {1, 0, 0};
    if(L <= tm) res = query(ls, tl, tm, L, R);
    if(R > tm) res = res * query(rs, tm + 1, tr, L, R);
    return res;
}
LL query(int n, int L, int R){
    M x = query(1, 1, n, L, R - 1);
    return x.C * power(mod + 1 - x.B, mod - 2) % mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i += 1){
        cin >> p[i];
        p[i] = p[i] * power(100, mod - 2) % mod;
        a[i] = {p[i], (1 + mod - p[i]) % mod, 1};
    }
    build(1, 1, n);
    set<int> s;
    s.insert(1);
    s.insert(n + 1);
    LL ans = query(n, 1, n + 1);
    for(int i = 1; i <= q; i += 1){
        int u;
        cin >> u;
        if(not s.count(u)){
            auto it = s.lower_bound(u);
            int r = *it;
            int l = *--it;
            ans -= query(n, l, r);
            ans += query(n, l, u);
            ans += query(n, u, r);
            ans = (ans + mod) % mod;
            s.insert(u);
        }
        else{
            auto it = s.upper_bound(u);
            int r = *it--;
            int l = *--it;
            ans += query(n, l, r);
            ans -= query(n, l, u);
            ans -= query(n, u, r);
            ans = (ans + 2 * mod) % mod;
            s.erase(u);
        }
        cout << ans << "\n";
    }
    return 0;
}