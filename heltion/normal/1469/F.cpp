#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000;
LL sum[maxn << 2], tag[maxn << 2];
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
void add(int v, int tl, int tr, LL d){
    sum[v] += (tr - tl + 1) * d;
    tag[v] += d;
}
void push_down(int v, int tl, int tr){
    add(ls, tl, tm, tag[v]);
    add(rs, tm + 1, tr, tag[v]);
    tag[v] = 0;
}
void add(int v, int tl, int tr, int L, int R, LL d){
    if(tl >= L and tr <= R){
        add(v, tl, tr, d);
        return;
    }
    push_down(v, tl, tr);
    if(L <= tm) add(ls, tl, tm, L, R, d);
    if(R > tm) add(rs, tm + 1, tr, L, R, d);
    sum[v] = sum[ls] + sum[rs];
}
LL get(int v, int tl, int tr, int L, int R){
    if(tl >= L and tr <= R) return sum[v];
    push_down(v, tl, tr);
    LL res = 0;
    if(L <= tm) res += get(ls, tl, tm, L, R);
    if(R > tm) res += get(rs, tm + 1, tr, L, R);
    return res;
}
LL find(int v, int tl, int tr, int k){
    if(sum[v] < k) return -1;
    if(tl == tr) return tm;
    push_down(v, tl, tr);
    if(sum[ls] >= k) return find(ls, tl, tm, k);
    return find(rs, tm + 1, tr, k - sum[ls]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, k;
    cin >> n >> k;
    vector<LL> v(n);
    for(LL& x : v) cin >> x;
    sort(v.begin(), v.end(), greater<LL>());
    add(1, 0, maxn - 1, 0, 0, 1);
    LL ans = -1;
    for(int i = 0, j = 0; i < n; i += 1){
        while(get(1, 0, maxn - 1, j, j) == 0)
            j += 1;
        add(1, 0, maxn - 1, j, j, -1);
        int L = (v[i] - 1) / 2, R = v[i] - 1 - L;
        add(1, 0, maxn - 1, j + 2, j + 2 + L - 1, 1);
        add(1, 0, maxn - 1, j + 2, j + 2 + R - 1, 1);
        LL pans = find(1, 0, maxn - 1, k);
        if(pans != -1) if(ans == -1 or ans > pans) ans = pans;
    }
    cout << ans;
    return 0;
}