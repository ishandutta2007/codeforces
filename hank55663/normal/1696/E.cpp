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
#define index Index
#define MXN 1000000
LL fra[500005];
LL inv[500005];
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
void solve(){
    int n;
    scanf("%d",&n);
    fra[0]=1;
    for(int i = 1;i<=500000;i++)fra[i]=fra[i-1]*i%mod;
    inv[500000]=f_pow(fra[500000],mod-2);
    for(int i = 499999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    int a[200005];
    LL ans=0;
    for(int i = 0;i<=n;i++){
        scanf("%d",&a[i]);
       }
       for(int i = 0;i<=n;i++){
    //       printf("%d %d\n",i+a[i],a[i]-1);
       ans+=C(i+a[i],a[i]-1);

    }
    printf("%lld\n",ans%mod);
}
int main(){
 //   srand(time(NULL));
    int t=1;00000;
  //  scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}