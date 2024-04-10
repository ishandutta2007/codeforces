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
int mod=998244353;
LL fra[200005];
LL inv[200005];
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
    char c[100005];
    int n;
    scanf("%d %s",&n,c);
    int cnt=0,cnt2=0;
    int tot=0;
    for(int i = 0;i<n;i++){
        if(c[i]=='0')cnt++,cnt2+=tot/2,tot=0;
        else tot++;
    }
    cnt2+=tot/2;
    printf("%lld\n",fra[cnt+cnt2]*inv[cnt]%mod*inv[cnt2]%mod);
}
int main(){
    fra[0]=1;
    for(int i = 1;i<=200000;i++)fra[i]=fra[i-1]*i%mod;
    inv[200000]=f_pow(fra[200000],mod-2);
    for(int i = 199999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}