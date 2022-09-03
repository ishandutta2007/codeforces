#include<bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("O3,unroll-loops")
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
void solve(){
    LL n;
    scanf("%lld",&n);
    LL cal[20];
    for(int i = 0;i<20;i++)cal[0]=1;
    for(int i = 1;i<20;i++)cal[i]=cal[i-1]*i;
   // printf("%lld\n",cal[16]);
    LL ans=100;
    for(int i = 0;i<1<<16;i++){
        LL sum=0;
        for(int j  =0;j<16;j++){
            if(i&(1<<j))sum+=cal[j];
        }
        if(i&3)continue;
        if(n>=sum){
            ans=min(ans,(LL)__builtin_popcount(i)+(LL)__builtin_popcountll(n-sum));
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}