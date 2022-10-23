#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int a[500005];
LL dp[500005];
const int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
/*
    a=i*i/(n*(n-1)/2);
    x=a*last+(1-a)*x+1;
*/
void solve(){
    LL n;
    scanf("%lld",&n);
    int cnt=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        cnt+=a[i];
    }
    int tot=0;
    for(int i = n-1;i>=n-cnt;i--){
        if(a[i]==0)tot++;
    }
    dp[0]=0;
    for(LL i = 1;i<=tot;i++){
        LL a=i*i%mod*f_pow((n*(n-1)/2)%mod,mod-2)%mod;
        dp[i]=(a*dp[i-1]+1)%mod*f_pow(a,mod-2)%mod;
    //    printf("%lld\n",dp[i]);
    }
    printf("%lld\n",dp[tot]);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}