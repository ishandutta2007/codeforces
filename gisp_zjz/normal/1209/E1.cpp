#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tmp[2][4096],vs[4096],dp[4096],_,n,m,a[2005][44],f[2105][4096];
void Max(int &x,int y){if (y>x) x=y;}
void solve(){
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> a[j][i];
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            a[i][j+n]=a[i][j];
    memset(dp,0,sizeof(dp));
    for (int i=0;i<m;i++){
        for (int v=0;v<(1<<n);v++) vs[v]=dp[v];
        for (int k=0;k<n;k++){
            int o=0;
            for (int v=0;v<(1<<n);v++) tmp[o][v]=dp[v];
            for (int j=0;j<n;j++){
                for (int v=0;v<(1<<n);v++){
                    tmp[o^1][v]=tmp[o][v];
                    if (v&(1<<j)) Max(tmp[o^1][v],tmp[o][v^(1<<j)]+a[i][k+j]);
                }
                o^=1;
            }
            for (int v=0;v<(1<<n);v++) Max(vs[v],tmp[o][v]);
        }
        for (int v=0;v<(1<<n);v++) dp[v]=vs[v];
    }
    cout << dp[(1<<n)-1] << endl;
}
int main(){
    int _; cin >> _; while (_--) solve();
    return 0;
}