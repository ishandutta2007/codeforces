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
#define MXN 3000000
LL win[14][1<<14];
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
LL pro[14][14];
LL dp[1<<14];

void solve(){
    int n;
    scanf("%d",&n);
    int a[14];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i!=j){
                pro[i][j]=a[i]*f_pow(a[i]+a[j],mod-2)%mod;
            }
        }
    }
    for(int i = 0;i<n;i++){
        win[i][0]=1;
        for(int j=1;j<(1<<n);j++){
            if(j&(1<<i))continue;
            int k=j&-j;
            int kn=__builtin_popcount(k-1);
            win[i][j]=win[i][j-k]*pro[i][kn]%mod;
          //  printf("%d %d %d\n",i,j,win[i][j]);
        }
    }
    int mask=1<<n;
    mask--;
    LL ans=0;
    for(int i = 0;i<(1<<n);i++){
        dp[i]=1;
        int popca=__builtin_popcount(i);
        for(int j = 0;j<n;j++){
            if(i&(1<<j)){
                dp[i]*=win[j][mask-i];
                dp[i]%=mod;
            }
        }
        LL tmp=dp[i];
       // printf("ori %lld\n",dp[i]);
        for(int k = (i-1)&i;k;k=(k-1)&i){
            LL pro2=1;
            for(int j = 0;j<n;j++){
                if(k&(1<<j));
                else if(i&(1<<j)){
                    pro2*=win[j][mask-i];
                    pro2%=mod;
                }
            }
            /*int popc=__builtin_popcount(k);
            if((popca-popc)%2==0)dp[i]+=pro2;
            else dp[i]-=pro2;*/
            dp[i]-=dp[k]*pro2%mod;
            dp[i]=(dp[i]%mod+mod)%mod;
            //printf("sub %lld %lld\n",k,pro2);
        }
        ans+=dp[i]*popca%mod;
       //  printf("%lld\n",dp[i]);
        ans%=mod;
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
*/