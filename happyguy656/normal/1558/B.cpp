#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int abc;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
typedef pair<int,int>pii;
int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=4e6+3;
ll dp[mxn],hh[mxn];int n,mod;

int main(){
    scanf("%d%d",&n,&mod);
    ll ss=0;
    for(int i=1;i<=n;++i){
        (hh[i]+=hh[i-1])%=mod;dp[i]=(hh[i]+ss)%mod;dp[1]=1;(ss+=dp[i])%=mod;
        for(int j=2;j*i<=n;++j){hh[j*i]+=dp[i];int k=j*(i+1);if(k<=n)hh[k]-=dp[i];}
    }
    printf("%lld\n",(dp[n]%mod+mod)%mod);
    return 0;
}