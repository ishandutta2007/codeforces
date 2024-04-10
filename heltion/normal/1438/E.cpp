#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
LL A[maxn], S[maxn];
struct node{
    LL max;
}nodes[maxn << 2];
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
void build(int v, int tl, int tr){
    if(tl == tr) nodes[v].max = A[tm];
    else{
        build(ls, tl, tm);
        build(rs, tm + 1, tr);
        nodes[v].max = max(nodes[ls].max, nodes[rs].max);
    }
}
int query(int v, int tl, int tr, int L, LL x){
    if(L > tr) return maxn;
    if(nodes[v].max < x) return maxn;
    if(tl == tr) return tm;
    if(tl >= L){
        if(nodes[ls].max >= x) return query(ls, tl, tm, L, x);
        return query(rs, tm + 1, tr, L, x);
    }
    if(tm >= L){
        int r = query(ls, tl, tm, L, x);
        if(r != maxn) return r;
    }
    return query(rs, tm + 1, tr, L, x);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        cin >> A[i];
        S[i] = A[i] + S[i - 1];
    }
    build(1, 1, n);
    for(int i = 1; i + 2 <= n; i += 1){
        int j = i + 2;
        while(j <= n){
            if((A[i] ^ A[j]) == S[j - 1] - S[i])
                ans += 1;
            j = query(1, 1, n, j + 1, S[j] - S[i] - A[i]);
        }
    }
    cout << ans;
    return 0;
}