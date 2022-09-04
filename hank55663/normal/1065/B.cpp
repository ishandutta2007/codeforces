#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
    LL n,m;
    scanf("%lld %lld",&n,&m);
    printf("%lld ",max(n-2*m,0ll));
    LL ans=0;
    for(LL i=0;i<=n;i++){
        if(i*(i-1)/2>=m){
            //printf("%lld\n",n*(n-1)
            ans=n-i;
            break;
        }
    }
    printf("%lld\n",ans);
}