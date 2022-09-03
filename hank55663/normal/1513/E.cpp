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
const int mod=1e9+7;
LL fra[100005];
LL inv[100005];
LL f_pow(LL a,LL b){
    LL res=1,tmp=a;
    while(b){
        if(b&1)res=res*tmp%mod;
        tmp=tmp*tmp%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    fra[0]=1;
    for(int i = 1;i<=100000;i++)fra[i]=fra[i-1]*i%mod;
    inv[100000]=f_pow(fra[100000],mod-2);
    for(int i = 99999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    int n;
    scanf("%d",&n);
    int a[100005];
    LL sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum%n!=0){
        printf("0\n");
        return ;
    }
    sum/=n;
    int cnt1=0,cnt2=0;
    for(int i = 0;i<n;i++){
        if(a[i]>sum)cnt1++;
        if(a[i]<sum)cnt2++;
    }
    if(cnt1==0){
        printf("1\n");
        return;
    }
    if(cnt1==1||cnt2==1){
        map<int,int> m;
        for(int i = 0;i<n;i++)m[a[i]]++;
        LL ans=fra[n];
        for(auto it:m){
            ans=ans*inv[it.y]%mod;
        }
        printf("%lld\n",ans);
        return ;
    }
     map<int,int> m;
        for(int i = 0;i<n;i++)m[a[i]]++;
    LL ans=fra[n];
    for(auto it:m){
        ans=ans*inv[it.y]%mod;
    }
    //ans*=inv[n-cnt1-cnt2];
    ans%=mod;
    ans*=inv[cnt1+cnt2]*2;
    ans%=mod;
    ans*=fra[cnt1];
    ans%=mod;
    ans*=fra[cnt2];
    ans%=mod;
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}