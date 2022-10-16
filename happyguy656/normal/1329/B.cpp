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
//mt19937 rnd(time(0));
//int rd(int l,int r){return rnd()%(r-l+1)+l;}

int n,mod,a[33];
ll dp[33][33];

int main(){
    int ca;cin>>ca;while(ca--){
        cin>>n>>mod;
        for(int i=0;i<30;++i){
            int t=n>>i;if(t==0)a[i]=0;else if(t>1)a[i]=1<<i;else a[i]=n-(1<<i)+1;
        }
        ll s=a[0]+1,ans=a[0];
        for(int i=1;i<=30;++i){
            ll v=s*a[i]%mod;ans+=v;s+=v,s%=mod;
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}