#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    if(k==1){
        printf("%lld\n",n);
    }
    else{
        LL ans= 1;
        while(n){
            n>>= 1;
            ans<<= 1;
            //n+=(n&-n);
            //printf("%lld %d\n",n,__builtin_popcount(n));
            //getchar();
        }
        printf("%lld\n",ans-1);
    }
}