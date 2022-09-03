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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
LL fra[200005];
LL inv[200005];
int mod=1e9+7;
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
    if(b<0)return 0;
   // printf("%d %d\n",a,b);
    if(b>a)return 0;
   // printf("?%d %d %lld\n",a,b,fra[a]*inv[b]%mod*inv[a-b]%mod);
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(){
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    int num=min(-l+1,r-n);
    LL ans=C(n,n/2)*num%mod;
    if(n%2==1)ans=(ans+C(n,n/2)*num%mod);
    int ll=1,rr=n;
    //printf("%lld\n",ans);
    for(int i = num+1;ll<=rr;i++){
        if(l-ll>-i)ll++;
        if(r-rr<i)rr--;
        ans+=C(rr-ll+1,n/2-ll+1);
        ans%=mod;
        if(n%2==1)ans+=C(rr-ll+1,n/2-ll+2);
        ans%=mod;
       //  printf("%lld %d %d %d\n",ans,ll,rr,num);
    }
    printf("%lld\n",ans);
}
int main(){
    fra[0]=1;
    for(int i = 1;i<=200000;i++)fra[i]=fra[i-1]*i%mod;
    inv[200000]=f_pow(fra[200000],mod-2)%mod;
    for(int i = 199999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}