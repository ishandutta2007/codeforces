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
        LL n,m;
        scanf("%lld %lld",&n,&m);
        LL ans=n*(n+1)/2;
        n-=m;
        LL num=n/(m+1);
        LL a=n%(m+1),b=m+1-n%(m+1);
        ans-=num*(num+1)/2*b;
        ans-=(num+1)*(num+2)/2*a;
        printf("%lld\n",ans);
    }
}