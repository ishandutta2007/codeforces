#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000;
int l[maxn], r[maxn], t[maxn], x[maxn], xn;
vector<int> T[maxn];
struct{
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
    int added[maxn << 2], ma[maxn << 2];
    void add(int v, int d){
        added[v] += d;
        ma[v] += d;
    }
    void push_down(int v){
        add(ls, added[v]);
        add(rs, added[v]);
        added[v] = 0;
    }
    void add(int v, int tl, int tr, int L, int R, int d){
        if(tl >= L and tr <= R) add(v, d);
        else{
            push_down(v);
            if(L <= tm) add(ls, tl, tm, L, R, d);
            if(R > tm) add(rs, tm + 1, tr, L, R, d);
            ma[v] = max(ma[ls], ma[rs]);
        }
    }
    int query(int v, int tl, int tr, int L, int R){
        if(tl >= L and tr <= R) return ma[v];
        push_down(v);
        int res = 0;
        if(L <= tm) res = max(res, query(ls, tl, tm, L, R));
        if(R > tm) res = max(res, query(rs, tm + 1, tr, L, R));
        return res;
    }
}tree[2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        cin >> l[i] >> r[i] >> t[i];
        x[xn ++] = l[i];
        x[xn ++] = r[i];
    }
    sort(x + 1, x + xn + 1);
    xn = unique(x + 1, x + xn + 1) - x - 1;
    for(int i = 1; i <= n; i += 1){
        l[i] = lower_bound(x + 1, x + xn + 1, l[i]) - x;
        r[i] = lower_bound(x + 1, x + xn + 1, r[i]) - x;
        t[i] -= 1;
        T[r[i]].push_back(i);
    }
    int ans = 0;
    for(int j = 1; j <= xn; j += 1)
        for(int i : T[j]){
            tree[t[i] ^ 1].add(1, 0, xn, 0, l[i] - 1, 1);
            int pans = tree[t[i] ^ 1].query(1, 0, xn, 0, l[i] - 1);
            ans = max(ans, pans);
            int now = tree[t[i]].query(1, 0, xn, r[i], r[i]);
            if(pans > now) tree[t[i]].add(1, 0, xn, r[i], r[i], pans - now);
        }
    cout << ans;
    return 0;
}