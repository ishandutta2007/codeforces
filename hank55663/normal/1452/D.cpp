#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    int n;
    scanf("%d",&n);
    LL dp[200005];
    dp[0]=1;
    dp[1]=(mod+1)/2;
    LL even=1,odd=dp[1];
    int l=0;
    for(int i = 2;i<=n;i++){
        if(i%2==0){
            dp[i]=odd*f_pow(2,mod-2)%mod;
            even=(even*f_pow(4,mod-2)%mod+dp[i])%mod;
        }
        else{
            dp[i]=even*f_pow(2,mod-2)%mod;
            odd=(odd*f_pow(4,mod-2)%mod+dp[i])%mod;
        }
    }
    printf("%lld\n",dp[n]);
}

int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}