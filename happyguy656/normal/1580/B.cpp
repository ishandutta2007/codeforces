#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd(time(0));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

int n,m,k,mod;
ull C[103][103],dp[103][103][103],jc[103];
int z[103][103];

int main(){
    cin>>n>>m>>k>>mod;
    for(int i=0;i<=n;++i){C[i][0]=1;for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;}
    jc[0]=1;for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;
    for(int i=0;i<=n;++i)dp[i][0][0]=1;
    for(int i=1;i<=n;++i)dp[1][i][1]=jc[i],z[1][i]=1;
    for(int i=2;i<=m;++i)for(int j=1;j<=n;++j)for(int k=0;k<=j;++k){
        for(int x=1;x<=j;++x){
            ull s=0;
            for(int y=0;y<=k&&y<=z[i-1][x-1];++y)s+=dp[i-1][x-1][y]*dp[i-1][j-x][k-y],s%=mod;
            (dp[i][j][k]+=s*C[j-1][x-1])%=mod;
        }
        if(dp[i][j][k])z[i][j]=k;
    }
    cout<<dp[m][n][k]<<endl;
    return 0;
}