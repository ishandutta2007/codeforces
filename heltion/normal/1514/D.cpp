#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
constexpr int maxn = 300000 + 1;
struct Node{
    int cur, cnt;
    Node operator * (const Node& p)const{
        if(cur == p.cur) return {cur, cnt + p.cnt};
        if(cnt >= p.cnt) return {cur, cnt - p.cnt};
        return {p.cur, p.cnt - cnt};
    }
}t[maxn << 2];
int a[maxn];
vector<int> p[maxn];
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
void build(int v, int tl, int tr){
    if(tl == tr)
        t[v] = {a[tm], 1};
    if(tl < tr){
        build(ls, tl, tm);
        build(rs, tm + 1, tr);
        t[v] = t[ls] * t[rs];
    }
}
Node query(int v, int tl, int tr, int L, int R){
    if(tl >= L and tr <= R) return t[v];
    Node res = {0, 0};
    if(L <= tm) res = res * query(ls, tl, tm, L, R);
    if(R > tm) res = res * query(rs, tm + 1, tr, L, R);
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 1; i <= n; i += 1) p[a[i]].push_back(i);
    build(1, 1, n);
    for(int i = 1; i <= q; i += 1){
        int L, R;
        cin >> L >> R;
        auto v = query(1, 1, n, L, R);
        int x = R - L + 1;
        int y = v.cur;
        int z = upper_bound(p[y].begin(), p[y].end(), R) - lower_bound(p[y].begin(), p[y].end(), L);
        cout << max(2 * z - x, 1) << "\n";
    }
    return 0;
}