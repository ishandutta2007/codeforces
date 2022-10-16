#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a13=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a13;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

int n,mod;
ll dp[2][503*503];
int he[503];
int main(){
    for(int i=1;i<=500;++i)he[i]=he[i-1]+i-1;
    scanf("%d%d",&n,&mod);
    dp[1][0]=1;
    ll ans=0,an=0;
    for(int z=0,i=2;i<n;++i,z^=1){
        for(int j=0;j<=he[i]*2;++j){
            for(int k=1-i;k<=i-1;++k)if(j-he[i]-k+he[i-1]>=0)dp[z][j]+=dp[z^1][j-he[i]-k+he[i-1]]*(i-abs(k)),dp[z][j]%=mod;
        }
        ll su=0;an=0;
        for(int j=he[i];j>1;--j){
            su+=dp[z][j+he[i]],su%=mod;
            if(j<=i+1)an+=su*(i-j+2),ans%=mod;
        }
        an%=mod;for(int j=i+2;j<=n;++j)an=an*j%mod;
        ans+=an,ans%=mod;
        for(int j=0;j<=2*he[i-1];++j)dp[z^1][j]=0;
    }
    printf("%lld\n",ans);
    return 0;
}