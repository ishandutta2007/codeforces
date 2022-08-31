#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tmp[4096],vs[4096],dp[4096],_,n,m,tt[2005][44],a[2005][44],f[2105][4096],s[30],mxv[2050];
struct node{
    int id,val;
}A[2005];
bool cmp(node u,node v){return u.val>v.val;}
void Max(int &x,int y){if (y>x) x=y;}
void solve(){
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> tt[j][i];
    for (int i=0;i<m;i++){
        mxv[i]=0;
        for (int j=0;j<n;j++) Max(mxv[i],tt[i][j]);
        A[i]=(node){i,mxv[i]};
    }
    sort(A,A+m,cmp);
    m=min(m,n);
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            a[i][j]=tt[A[i].id][j];
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            a[i][j+n]=a[i][j];
    memset(dp,0,sizeof(dp));
    for (int i=0;i<m;i++){
        for (int v=0;v<(1<<n);v++) vs[v]=dp[v];
        for (int k=0;k<n;k++){
            int o=0;
            for (int j=0;j<n;j++) s[j]=a[i][k+j];
            for (int v=0;v<(1<<n);v++) tmp[v]=dp[v];
            for (int v=0;v<(1<<n);v++)
                for (int j=0;j<n;j++)
                    if (v&(1<<j)) Max(tmp[v],tmp[v^(1<<j)]+s[j]);
            for (int v=0;v<(1<<n);v++) Max(vs[v],tmp[v]);
        }
        for (int v=0;v<(1<<n);v++) dp[v]=vs[v];
    }
    cout << dp[(1<<n)-1] << endl;
}
int main(){
    int _; cin >> _; while (_--) solve();
    return 0;
}