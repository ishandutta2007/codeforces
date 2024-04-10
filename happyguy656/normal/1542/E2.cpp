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

int n,mod;const int T=500*250;
ll dp[2][503*503],sm[2][503*503];
int he[503];
int main(){
    for(int i=1;i<=500;++i)he[i]=he[i-1]+i-1;
    scanf("%d%d",&n,&mod);
    dp[1][T]=1;for(int i=T;i<=2*T;++i)sm[1][i]=1;
    ll ans=0,an=0;
    for(int z=0,i=2;i<n;++i,z^=1){
        for(int j=-he[i];j<=he[i];++j){
            ll&ff=dp[z][j+T];
            if(j==-he[i-1]){
                for(int k=1-i;k<=i-1;++k)ff+=dp[z^1][j+k+T]*(i-abs(k)),ff%=mod;
            }else{
                ff=dp[z][j-1+T];
                ff+=(sm[z^1][j+i-1+T]-sm[z^1][j-1+T])-(sm[z^1][j-1+T]-sm[z^1][j+1-i+T-2]);
                ff%=mod;
                assert(j+i-1<=T);assert(j+1-i+T-2>=0);
            }
        }
        assert(!dp[z][0]);
        an=0;
        for(int j=T-he[i];j<=T+he[i+1]+i;++j)sm[z][j]=(sm[z][j-1]+dp[z][j])%mod;
        for(int j=1;j<=i;++j)an+=(sm[z][he[i]+T]-sm[z][j+T])*(i-j+1),an%=mod;
        for(int j=i+2;j<=n;++j)an=an*j%mod;
        ans+=an,ans%=mod;
        for(int j=-he[i-1]+T;j<=he[i-1]+T;++j)dp[z^1][j]=0;
    }
    ans=(ans%mod+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}