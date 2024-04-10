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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005

int main(){
    LL d,k,a,b,t;
    scanf("%lld %lld %lld %lld %lld",&d,&k,&a,&b,&t);
    LL ans=max(d-k,0ll)*b+min(k,d)*a;
    int cnt=0;
    for(LL x=(d-1)/k;x>=0;x--){
        ans=min(ans,t*x+min(k*(x+1),d)*a+max(d-k*(x+1),0ll)*b);
        cnt++;
        if(cnt==10)break;
    }
    printf("%lld\n",ans);
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/