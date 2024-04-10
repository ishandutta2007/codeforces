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
using namespace std;
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
LL fra[200005];
LL inv[200005];
LL C(int a,int b){
    if(a<b)return 0;
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int l = 0;
    LL ans=0;
    for(int i = 0;i<n;i++){
        while(a[i]-a[l]>k)l++;
        ans+=C(i-l,m-1);
        ans%=mod;
    }  
    printf("%lld\n",ans);
}
int main(){
    fra[0]=1;
    for(int i =1;i<=200000;i++)fra[i]=fra[i-1]*i%mod;
    inv[200000]=f_pow(fra[200000],mod-2);
    for(int i = 199999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
}