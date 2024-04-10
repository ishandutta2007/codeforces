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
LL fra[1000005];
LL inv[1000005];
int cnt[1000005];
void solve(){
    int n;
    scanf("%d",&n);
    map<int,int> m;
   // vector<int> v;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        m[x]++;
    }
    if(m.size()==1){
        printf("1\n");
        return;
    }
    LL ans=0,tot=0,tot2=0;

    fill(cnt,cnt+n+1,0);
    for(int i = 1;i<=n;i++)cnt[__gcd(i,n)]++;
    int tgcd=0;
    for(auto it:m){
        tgcd=__gcd(it.y,tgcd);
    }
    for(int i = 1;i<=n;i++){
        if(n%i==0&&tgcd%i==0){
            tot2++;
            int ok=1;
            /*for(auto it:m){
                if(it.y%i!=0){
                    ok=0;
                    break;
                }
              //  printf("%d ",it.y);
            }*/
          //  printf("\n");
            if(ok){
                LL sum=fra[n/i];
                for(auto it:m){
                    sum=sum*inv[it.y/i]%mod;
                }
                tot+=sum*cnt[n/i]%mod;
                tot%=mod;
               // printf("%lld ",sum);
                LL sum2=0;
                sum=sum*inv[n/i]%mod;
                for(auto it:m){
                    if(it.y/i>=2){
                        sum2+=sum*fra[it.y/i]%mod*inv[it.y/i-2]%mod*fra[n/i-2]%mod;
                        sum2%=mod;
                    }
                }
                ans+=sum2*n%mod*cnt[n/i]%mod;
               // printf("%lld %d\n",sum2*n,i);
                ans%=mod;
            }
        }
    }
   // printf("%lld %lld %lld\n",ans,tot,tot2);
    printf("%lld\n",((n-ans*f_pow(tot,mod-2)%mod)%mod+mod)%mod);
}
int main(){
    fra[0]=1;
    for(int i = 1;i<=1000000;i++)fra[i]=fra[i-1]*i%mod;
    inv[1000000]=f_pow(fra[1000000],mod-2);
    for(int i = 999999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y

36
0123
0123 4567
*/