#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 1000005
vector<LL> v[200005];
int mobi[200005];
LL cnt[200005];
int mod=998244353;
LL f_pow(LL a,LL b){
    if(b<0)return 0;
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int prime[200005];
void solve(){
    fill(mobi,mobi+200005,1);
    
    for(int i = 2;i<200005;i++){
        if(prime[i]==0)
        for(int j = i;j<200005;j+=i){
            prime[j]=1;
            if(j/i%i==0)mobi[j]=0;
            mobi[j]*=-1;
        }
    }
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        cnt[a]=b;
    }
    LL ans=0;
    for(int i = 1;i<100005;i++){
        if(mobi[i]==0)continue;
        LL sum=0,tot=0;
        for(int j = i;j<100005;j+=i){
            tot+=cnt[j];
            sum+=cnt[j]*j;
            sum%=mod;
        }
        if(tot==1)continue;
        LL res=0;
        LL tmp=f_pow(2,tot-2);
        LL tmp2=f_pow(2,tot-3);
        for(int j =i;j<100005;j+=i){
            res+=tmp2*(tot%mod+mod-2)%mod*(sum-j)%mod*j%mod*cnt[j]%mod;
            res+=tmp%mod*(sum-j)%mod*j%mod*cnt[j]%mod;
            res+=tmp*(tot%mod+mod-1)%mod*j%mod*j%mod*cnt[j]%mod;
            res%=mod;
        }
        //if(res)
       // printf("%d %lld %lld %lld %d\n",i,res,tot,sum,mobi[i]);
        ans+=mobi[i]*res;
        ans=(ans%mod+mod)%mod;
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    int n;
    while(t--){
        solve();
    }
}
/*
32 16 15 20 13 2 1
16 8 25 30 10 0 0
5 6 30 24 16 1 1
18 21 39 12 30 1 1
10 8 29 13 36 1 1
24 25 30 31 3 0 0
21 22 10 27 33 0 0
*/