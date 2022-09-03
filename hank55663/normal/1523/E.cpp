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
LL fra[2000005];
LL inv[2000005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL C(LL a,LL b){
    if(b>a)return 0;
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    LL sum=0;
    for(int i = 1;i<=n;i++){
        sum+=C(n-(k-1)*(i-1),i)*fra[i]%mod*fra[n-i]%mod;
        sum%=mod;
        if(C(n-(k-1)*(i-1),i)==0)break;
    }
    printf("%lld\n",(sum*inv[n]+1)%mod);
}
/*
C[n-(k-1)*(i-1)][n-i-(k-1)*(i+1)]
//[n-k*i+i-k+1][i]
*/
int main(){
    fra[0]=1;
    for(int i = 1;i<=2000000;i++)fra[i]=fra[i-1]*i%mod;
    inv[2000000]=f_pow(fra[2000000],mod-2);
    for(int i = 1999999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/