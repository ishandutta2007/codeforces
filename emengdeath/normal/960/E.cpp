#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
const long long MOD=1e9+7;
int n;
long long ans;
int g[N],a[N*2][2];
long long w[N];
long long f[N][2];
void ins(int x,int y){
    static int sum=1;
    a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void dfs(int x,int fa){
    f[x][0]=1;
    for (int i=g[x];i;i=a[i][1])
        if (a[i][0]!=fa){
            dfs(a[i][0],x);
            (ans+=w[x]*((f[x][0]*(f[a[i][0]][0]+f[a[i][0]][1])%MOD-f[x][1]*(f[a[i][0]][0]+f[a[i][0]][1])%MOD+f[a[i][0]][1]*(f[x][0]+f[x][1])%MOD-f[a[i][0]][0]*(f[x][0]+f[x][1])%MOD)%MOD)%MOD)%=MOD;
            f[x][0]+=f[a[i][0]][1];
            f[x][1]+=f[a[i][0]][0];
        }
}
void dfs(int x,int fa,long long f0,long long f1){
    (ans+=w[x]*((f0*(f[x][0]+f[x][1])%MOD-f1*(f[x][0]+f[x][1])%MOD+f[x][0]*(f0+f1)%MOD-f[x][1]*(f0+f1)%MOD)%MOD)%MOD)%=MOD;
    for (int i=g[x];i;i=a[i][1])
        if (a[i][0]!=fa)
            dfs(a[i][0],x,(f1+f[x][1]-f[a[i][0]][0])%MOD,(f0+f[x][0]-f[a[i][0]][1])%MOD);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>w[i],(ans+=w[i])%=MOD;
    for (int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        ins(x,y),ins(y,x);
    }
    dfs(1,0);
    dfs(1,0,0,0);
    (ans+=MOD)%=MOD;
    cout<<ans;
    return 0;
}