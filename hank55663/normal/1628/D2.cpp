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
LL fra[1000005],inv[1000005];
const int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL C(int a,int b){
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
LL pw[1000005];
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    if(n==m){
        printf("%lld\n",k*1ll*m%mod);
    }
    else{
        LL ans=0;
        for(int i = 1;i<=m;i++){
            LL val=k*1ll*i%mod;
            ans+=C(m-i+n-m-1,n-m-1)*val%mod*pw[n-m+m-i]%mod;
            ans%=mod;
         //   printf("%lld %lld %lld\n",C(m-i+n-m-1,n-m-1),val,n-m+m-i);
        }
        printf("%lld\n",ans);
    }

}
int main(){
    pw[0]=1;
    for(int i = 1;i<=1000000;i++)pw[i]=pw[i-1]*2%mod;
    for(int i = 1;i<=1000000;i++)pw[i]=f_pow(pw[i],mod-2);
    fra[0]=1;
    for(int i = 1;i<=1000000;i++)fra[i]=fra[i-1]*i%mod;
    inv[1000000]=f_pow(fra[1000000],mod-2);
    for(int i = 999999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}