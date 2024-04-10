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

const int mod=998244353;
int n,a[555];char ss[3];
int ls[555],nn,vs[555],px[555];
ll dp[2][555];
int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i){scanf("%s",ss);if(ss[0]=='+')scanf("%d",a+i),ls[++nn]=a[i];}
    sort(ls+1,ls+nn+1);
    for(int i=1;i<=n;++i)if(a[i]){
        for(int j=1;j<=nn;++j)if(ls[j]==a[i]&&!vs[j]){vs[j]=1,px[i]=j;break;}
        assert(px[i]);
    }
    ll ans=0;
    for(int t=1;t<=n;++t)if(a[t]){
        memset(dp,0,sizeof(dp));dp[0][0]=1;
        for(int z=0,i=0;i<n;++i,z^=1){
            memset(dp[z^1],0,sizeof(dp[0]));
            for(int j=0;j<=n;++j)if(dp[z][j]){
                dp[z][j]%=mod;
                dp[z^1][j]+=dp[z][j];
                if(i+1==t)continue;
                if(!a[i+1]){
                    if(j)dp[z^1][j-1]+=dp[z][j];
                    else if(i+1<t)dp[z^1][0]+=dp[z][j];
                }
                else if(px[i+1]>px[t])dp[z^1][j]+=dp[z][j];
                else dp[z^1][j+1]+=dp[z][j];
            }
        }
        ll su=0;for(int i=0;i<=n;++i)su+=dp[n&1][i],su%=mod;
        ans+=su*a[t],ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}