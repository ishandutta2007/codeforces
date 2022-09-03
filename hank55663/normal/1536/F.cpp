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
const int mod=1e9+7;
LL fra[1000005];
LL inv[1000005];
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
    if(b>a)return 0;
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(){
    LL fra2[1000005];
    fra2[2]=1;
    for(int i = 4;i<=1000000;i+=2)fra2[i]=fra2[i-2]*(i-2)*2%mod;
    fra[0]=1;
    for(int i = 1;i<=1000000;i++)fra[i]=fra[i-1]*i%mod;
    inv[1000000]=f_pow(fra[1000000],mod-2);
    for(int i=999999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;    
    int n;
    scanf("%d",&n);
    LL ans=0;
    for(int i = 2;i<=n;i+=2){
        ans+=fra[i-1]*C(i,n-i)%mod;
        ans%=mod;
    }
    ans=ans*n*2%mod;
    printf("%lld\n",ans);
}
int main(){
    int t=1;
//    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/