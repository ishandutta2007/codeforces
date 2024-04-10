#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef pair<int,int>pii;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=4003,mod=1e9+7,B=13331,M=998244353;
char s1[mxn],s2[mxn],ss[mxn];
int n,m;ll dp[mxn][mxn][2],ans,mi[mxn],h1[mxn],h2[mxn],h3[mxn],h4[mxn];
ll HA(int l,int r){if(l<1||r>n)return -1;return (h1[r]-h1[l-1]*mi[r-l+1]+1ll*M*M)%M;}
ll HB(int l,int r){if(l<1||r>n)return -2;return (h2[r]-h2[l-1]*mi[r-l+1]+1ll*M*M)%M;}
ll HC(int l,int r){if(l<1||r>m)return -3;return (h3[r]-h3[l-1]*mi[r-l+1]+1ll*M*M)%M;}
ll CH(int l,int r){if(l<1||r>m)return -4;return (h4[l]-h4[r+1]*mi[r-l+1]+1ll*M*M)%M;}
void wk(bool tp){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)for(int j=2;j<=m;j+=2){
        int k=j/2;
        dp[i][j][0]=HB(i-k+1,i)==CH(1,k)&&HA(i-k+1,i)==HC(k+1,j);
        dp[i][j][1]=HA(i-k+1,i)==CH(1,k)&&HB(i-k+1,i)==HC(k+1,j);
        if(j==m)ans+=dp[i][j][0]+dp[i][j][1];
    }
    if(!tp&&m==2)ans=0;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
        if(ss[j]==s1[i]){
            if(j==1)++dp[i][j][0];
            dp[i][j][0]%=mod;
            int k=(m-j)>>1;if(j+2*k==m&&k&&HA(i+1,i+k)==HC(j+1,j+k)&&HB(i+1,i+k)==CH(m-k+1,m))ans+=dp[i][j][0];
            if(ss[j+1]==s1[i+1]){dp[i+1][j+1][0]+=dp[i][j][0],dp[i+1][j+2][1]+=dp[i][j][0];if(j+1==m)ans+=dp[i][j][0];}
        }
        if(ss[j]==s2[i]){
            if(j==1)++dp[i][j][1];
            dp[i][j][1]%=mod;
            int k=(m-j)>>1;if(j+2*k==m&&k&&HB(i+1,i+k)==HC(j+1,j+k)&&HA(i+1,i+k)==CH(m-k+1,m))ans+=dp[i][j][1];
            if(ss[j+1]==s2[i+1]){dp[i+1][j+1][1]+=dp[i][j][1],dp[i+1][j+2][0]+=dp[i][j][1];if(j+1==m)ans+=dp[i][j][1];}
        }
    }
}
int main(){
    mi[0]=1;for(int i=1;i<=2000;++i)mi[i]=mi[i-1]*B%M;
    scanf("%s%s%s",s1+1,s2+1,ss+1);n=strlen(s1+1),m=strlen(ss+1);
    if(m==1){int r=0;for(int i=1;i<=n;++i)r+=s1[i]==ss[1],r+=s2[i]==ss[1];printf("%d\n",r);return 0;}
    for(int i=1;i<=n;++i)h1[i]=(h1[i-1]*B+s1[i])%M,h2[i]=(h2[i-1]*B+s2[i])%M;
    for(int i=1;i<=m;++i)h3[i]=(h3[i-1]*B+ss[i])%M;for(int i=m;i;--i)h4[i]=(h4[i+1]*B+ss[i])%M;
    wk(0);
    reverse(s1+1,s1+n+1),reverse(s2+1,s2+n+1);
    for(int i=1;i<=n;++i)h1[i]=(h1[i-1]*B+s1[i])%M,h2[i]=(h2[i-1]*B+s2[i])%M;
    wk(1);
    ans=(ans%mod+mod)%mod;printf("%lld\n",ans);
    return 0;
}