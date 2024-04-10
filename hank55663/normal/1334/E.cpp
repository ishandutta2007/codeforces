#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
LL fra[400005];
LL inv[400005];
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
  //  int t;
  //  scanf("%d",&t);
    fra[0]=1;
    for(int i = 1;i<400005;i++){
        fra[i]=fra[i-1]*i%mod;
    }
    inv[400000]=f_pow(fra[400000],mod-2);
    for(int i = 399999;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
   // while(t--){
        LL d;
        scanf("%lld",&d);
        vector<LL> prime;
        for(LL i = 2;i*i<=d;i++){
            if(d%i==0){
                prime.pb(i);
                while(d%i==0)d/=i;
            }
        }
        if(d!=1)prime.pb(d);
        LL q;
        scanf("%lld",&q);
        while(q--){
            LL u,v;
            scanf("%lld %lld",&u,&v);
            LL gcd=__gcd(u,v);
            u/=gcd,v/=gcd;
            LL sum=0,ans=1;
            for(auto it:prime){
                LL tmp=0;
                while(u%it==0){
                    u/=it;
                    tmp++;
                }
                ans*=inv[tmp];
                sum+=tmp;
                ans%=mod;
            }
            ans*=fra[sum];
            ans%=mod;
            sum=0;
            for(auto it:prime){
                LL tmp=0;
                while(v%it==0){
                    v/=it;
                    tmp++;
                }
                ans*=inv[tmp];
                sum+=tmp;
                ans%=mod;
            }
            ans*=fra[sum];
            ans%=mod;
            printf("%lld\n",ans);
        }
    //}
}
/*
1 2 1 3 1 4 1....1 n 2 3 2 4 2 5 2 6....2 n
*/