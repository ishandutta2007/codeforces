#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
constexpr int maxn = 500000;
int added[maxn << 2];
pair<int, int> mn[maxn << 2];
void add(int v, int d){
    mn[v].first += d;
    added[v] += d;
}
void push_down(int v){
    add(ls, added[v]);
    add(rs, added[v]);
    added[v] = 0;
}
pair<int, int> add(pair<int, int> p, pair<int, int> q){
    auto res = make_pair(min(p.first, q.first), 0);
    if(res.first == p.first) res.second += p.second;
    if(res.first == q.first) res.second += q.second;
    return res;
}
void add(int v, int tl, int tr, int L, int R, int d){
    if(tl >= L and tr <= R) add(v, d);
    else{
        push_down(v);
        if(L <= tm) add(ls, tl, tm, L, R, d);
        if(R > tm) add(rs, tm + 1, tr, L, R, d);
        mn[v] = add(mn[ls], mn[rs]);
    }
}
pair<int, int> query(int v, int tl, int tr, int L, int R){
    if(tl >= L and tr <= R) return mn[v];
    push_down(v);
    if(R <= tm) return query(ls, tl, tm, L, R);
    if(L > tm) return query(rs, tm + 1, tr, L, R);
    return add(query(ls, tl, tm, L, R), query(rs, tm + 1, tr, L, R));
}
void build(int v, int tl, int tr){
    if(tl == tr) mn[v] = {0, 1};
    else{
        build(ls, tl, tm);
        build(rs, tm + 1, tr);
        mn[v] = add(mn[ls], mn[rs]);
    }
}
vector<int> G[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    build(1, 1, n);
    LL ans = 0;
    set<int> s;
    for(int i = 1, a; i <= n; i += 1){
        cin >> a;
        if(i > 1) add(1, 1, n, 1, i - 1, -(int)s.size());
        if(G[a].size()) add(1, 1, n, G[a].back() + 1, n, 1);
        if(G[a].size() == 3) add(1, 1, n, 1, G[a][0], 1);
        if(G[a].size() > 3) add(1, 1, n, G[a][G[a].size() - 4] + 1, G[a][G[a].size() - 3], 1);
        G[a].push_back(i);
        s.insert(a);
        add(1, 1, n, 1, i, s.size());
        if(i < n) add(1, 1, n, i + 1, n, -1);
        if(G[a].size() == 3) add(1, 1, n, 1, G[a][0], -1);
        if(G[a].size() > 3) add(1, 1, n, G[a][G[a].size() - 4] + 1, G[a][G[a].size() - 3], -1);
        auto p = query(1, 1, n, 1, i);
        if(not p.first) ans += p.second;
        //for(int j = 1; j <= i; j += 1) cout << query(1, 1, n, j, j).first << " ";
        //cout << "\n";
    }
    cout << ans;
    return 0;
}