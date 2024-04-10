#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL n,g,b;
        scanf("%lld %lld %lld",&n,&g,&b);
        LL Max=1e18,Min=n-1;
        while(Max>Min+1){
            LL mid=(Max+Min)/2;
            LL good=mid/(g+b)*g+min(mid%(g+b),g);
            LL bad=min(mid-good,n/2);
            if(good+bad>=n){
                Max=mid;
            }
            else{
                Min=mid;
            }
        }
        printf("%lld\n",Max);
    }
}