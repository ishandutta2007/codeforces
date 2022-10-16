#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int> pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

int n,mod;
ll CS;
ll por(ll x,int y){ll res=1;for(;y;y>>=1){if(y&1)res=res*x%mod; x=x*x%mod;}return res;}
ll dp[2][2][403][403],C[403][403],t[403];
void juj(ll A[],ll B[],ll re[],int x,int y){
    ll X=C[x+y][x];
    int l=y;while(!B[l])++l;assert(l<=n);
    for(int i=x;i<=n;++i)if(A[i])for(int j=l;j+i<n;++j) (t[i+j+1]+=A[i]*B[j])%=mod;//,++CS;
    for(int i=x+y+1;i<=n;++i) (re[i]+=t[i]*X)%=mod,t[i]=0;
}
namespace tak1{
    ll dp[403][403],bin[403];
    void W(){
        bin[0]=1;for(int i=1;i<=n;++i)bin[i]=bin[i-1]*2%mod;
        dp[0][0]=1;
        for(int i=1;i<=n;++i)for(int j=1;j<=i;++j)for(int k=1;k<=j;++k)
            (dp[i+1][j]+=dp[i-k][j-k]*C[j][k]%mod*bin[k-1])%=mod;
        ll ans=0;for(int i=1;i<=n;++i)ans+=dp[n+1][i];
        printf("%lld\n",ans%mod);
    }
}

int main(){
    scanf("%d%d",&n,&mod);
    for(int i=0;i<=n;++i){C[i][0]=C[i][i]=1;for(int j=1;j<i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;}
    if(n>=200)return tak1::W(),0;
    dp[0][0][0][0]=dp[0][1][0][0]=dp[1][0][0][0]=dp[1][1][0][0]=dp[1][1][0][1]=1;
    for(int j=0;j<=n;++j){
    /*
        for(int i=j;i<=n;++i){
            for(int t=0;t<j;++t)for(int k=0;k<i;++k)
                (dp[0][0][j][i]+=dp[0][1][t][k]*dp[1][0][j-t-1][i-k-1]%mod*CC(j-1,t))%=mod,
                (dp[0][1][j][i]+=dp[0][1][t][k]*dp[1][1][j-t-1][i-k-1]%mod*CC(j-1,t))%=mod,
                (dp[1][0][j][i]+=dp[1][1][t][k]*dp[1][0][j-t-1][i-k-1]%mod*CC(j-1,t))%=mod,
                (dp[1][1][j][i]+=dp[1][1][t][k]*dp[1][1][j-t-1][i-k-1]%mod*CC(j-1,t))%=mod;
        }*/
        
        for(int i=0;i<j&&i+j<n;++i)
            juj(dp[0][1][j],dp[1][0][i],dp[0][0][i+j+1],j,i),
            juj(dp[0][1][j],dp[1][1][i],dp[0][1][i+j+1],j,i),
            juj(dp[1][1][j],dp[1][0][i],dp[1][0][i+j+1],j,i),
            juj(dp[1][1][j],dp[1][1][i],dp[1][1][i+j+1],j,i);
        for(int i=0;i<=j&&i+j<n;++i)
            juj(dp[0][1][i],dp[1][0][j],dp[0][0][i+j+1],i,j),
            juj(dp[0][1][i],dp[1][1][j],dp[0][1][i+j+1],i,j),
            juj(dp[1][1][i],dp[1][0][j],dp[1][0][i+j+1],i,j),
            juj(dp[1][1][i],dp[1][1][j],dp[1][1][i+j+1],i,j);

        dp[1][1][1][1]=0;
//        cout<<j<<endl;
    }
    ll ans=0;
    for(int i=1;i<=n;++i)ans+=dp[0][0][i][n];
    printf("%lld\n",ans%mod);
    return 0;
}