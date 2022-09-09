#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 5000 + 1;
LL x[maxn], y[maxn];
int v[maxn];
LL dis(int i, int j){
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> x[i] >> y[i];
    int si = 0, sj = 0;
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= n; j += 1)
            if(dis(i, j) > dis(si, sj)){
                si = i;
                sj = j;
            }
    cout << si << " " << sj << " ";
    v[si] = v[sj] = 1;
    for(int i = 3, x = sj; i <= n; i += 1){
        int y = x;
        for(int j = 1; j <= n; j += 1) if(not v[j])
            if(dis(j, x) > dis(y, x)) y = j;
        x = y;
        cout << x << " ";
        v[y] = 1;
    }
    return 0;
}