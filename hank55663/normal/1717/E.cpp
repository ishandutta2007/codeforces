#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
LL mobi[100005];
int isprime[100005];
int res[100005];
void solve(int T){
    fill(mobi,mobi+100005,1);
    fill(isprime,isprime+100005,1);
    for(int i = 2;i<100005;i++){
        if(isprime[i]){
            for(int j = i;j<100005;j+=i){
                isprime[j]=0;
                if(j/i%i==0)mobi[j]=0;
                else mobi[j]*=-1;
            }
        }
    }
    int n;
    scanf("%d",&n);
    for(int i = 2;i<=n;i++){
        res[i]=i-1;
        for(int  j =2;j*j<=i;j++){
            if(i%j==0){
                res[i]-=res[j];
                if(j*j!=i)res[i]-=res[i/j];
            }
        }
    }
    LL ans=0;
    for(int i = 2;i<n;i++){
        for(LL k = 1;i*k<n;k++){
            LL c=n-k*i;
            LL rres=c*k/__gcd(c,k);
            ans+=rres%mod*res[i]%mod;
            ans%=mod;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/