#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
int Next[200005][10];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int m,d,w;
        scanf("%d %d %d",&m,&d,&w);
        int gcd=__gcd(d-1,w);
        w/=gcd;
        int dd=min(m,d);
        int cnt=dd/w,more=dd%w;
        
        LL day=dd/w;
     //   printf("%lld\n",day);
        LL ans=day*(day-1)/2*(w-more)+day*(day+1)/2*more;
        printf("%lld\n",ans);
    }
}