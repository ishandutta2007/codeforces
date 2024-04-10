#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 2;
int tag[maxn << 2], sum[maxn << 2];
char s[maxn], f[maxn];
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
void build(int v, int tl, int tr){
    tag[v] = -1;
    if(tl == tr) sum[v] = f[tm] - '0';
    else{
        build(ls, tl, tm);
        build(rs, tm + 1, tr);
        sum[v] = sum[ls] + sum[rs];
    }
}
void setx(int v, int tl, int tr, int x){
    sum[v] = x * (tr - tl + 1);
    tag[v] = x;
}
void push_down(int v, int tl, int tr){
    if(tag[v] != -1){
        setx(ls, tl, tm, tag[v]);
        setx(rs, tm + 1, tr, tag[v]);
    }
    tag[v] = -1;
}
int get(int v, int tl, int tr, int L, int R){
    if(tl >= L and tr <= R)  return sum[v];
    push_down(v, tl, tr);
    int res = 0;
    if(L <= tm) res += get(ls, tl, tm, L, R);
    if(R > tm) res += get(rs, tm + 1, tr, L, R);
    return res; 
}
void setx(int v, int tl, int tr, int L, int R, int x){
    if(tl >= L and tr <= R) setx(v, tl, tr, x);
    else{
        push_down(v, tl, tr);
        if(L <= tm) setx(ls, tl, tm, L, R, x);
        if(R > tm) setx(rs, tm + 1, tr, L, R, x);
        sum[v] = sum[ls] + sum[rs];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, q;
        cin >> n >> q >> (s + 1) >> (f + 1);
        build(1, 1, n);
        vector<pair<int, int>> vp(q);
        for(auto& [l, r] : vp) cin >> l >> r;
        reverse(vp.begin(), vp.end());
        int ok = 1;
        for(auto& [l, r] : vp){
            int s = get(1, 1, n, l, r);
            if(s * 2 == r - l + 1){
                ok = 0;
                break;
            }
            setx(1, 1, n, l, r, s * 2 > r - l + 1);
        }
        for(int i = 1; i <= n; i += 1) if(get(1, 1, n, i, i) != s[i] - '0'){
            ok = 0;
            break;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}