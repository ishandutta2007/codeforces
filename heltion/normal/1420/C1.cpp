#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define ls (v << 1)
#define rs ((ls) | 1)
#define tm ((tl + tr) >> 1)
constexpr int maxn = 300000 + 1;
struct node{
    LL v[4];
    //++,+-,-+,--
}nodes[maxn << 2];
node operator * (const node& L, const node& R){
    node v;
    v.v[0] = max({L.v[0], R.v[0], L.v[0] + R.v[2], L.v[1] + R.v[0]});
    v.v[1] = max({L.v[1], R.v[1], L.v[0] + R.v[3], L.v[1] + R.v[1]});
    v.v[2] = max({L.v[2], R.v[2], L.v[2] + R.v[2], L.v[3] + R.v[0]});
    v.v[3] = max({L.v[3], R.v[3], L.v[2] + R.v[3], L.v[3] + R.v[1]});
    return v;
}
int a[maxn];
void build(int v, int tl, int tr){
    if(tl == tr){
        nodes[v].v[0] = a[tm];
        nodes[v].v[1] = -9e10;
        nodes[v].v[2] = -9e10;
        nodes[v].v[3] = -a[tm];
    }
    else{
        build(ls, tl, tm);
        build(rs, tm + 1, tr);
        nodes[v] = nodes[ls] * nodes[rs];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        build(1, 1, n);
        cout << max(nodes[1].v[0], nodes[1].v[1]) << "\n";
    }
    return 0;
}