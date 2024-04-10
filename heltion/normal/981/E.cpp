#include<bits/stdc++.h>
#define maxn 40000
std::bitset<maxn> ans;
namespace SGT{
    std::vector<int> v[maxn];
    std::bitset<maxn> bs[maxn];
    void update(int o, int l, int r, int L, int R, int x){
        if(l >= L and r <= R) v[o].push_back(x);
        else{
            int m = (l + r) / 2;
            if(L <= m) update(o * 2, l, m, L, R, x);
            if(R > m) update(o * 2 + 1, m + 1, r, L, R, x);
        }
    }
    void query(int o, int l, int r){
        for(int k : v[o]) bs[o] |= bs[o] << k;
        if(l == r) ans |= bs[o];
        else{
            int m = (l + r) / 2;
            bs[o * 2] = bs[o];
            bs[o * 2 + 1] = bs[o];
            query(o * 2, l, m);
            query(o * 2 + 1, m + 1, r);
        }
    }
}
int main(){
    int n, m, c = 0;
    scanf("%d %d", &n, &m);
    SGT::bs[1].set(0);
    for(int i = 0; i < m; i += 1){
        int L, R, x;
        scanf("%d %d %d", &L, &R, &x);
        SGT::update(1, 1, n, L, R, x);
    }
    SGT::query(1, 1, n);
    std::vector<int> hans;
    for(int i = 1; i <= n; i += 1)
        if(ans.test(i)) hans.push_back(i);
    printf("%d\n", hans.size());
    for(int k : hans) printf("%d ", k);
}