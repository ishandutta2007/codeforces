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

int main(){
    int t;
    scanf("%d",&t);
    pll p[300005];
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            scanf("%lld %lld",&p[i].x,&p[i].y);
        }
        for(int i = 1;i<n;i++){
            p[i].x-=p[i-1].y;
        }
        p[0].x-=p[n-1].y;
        LL ans=0;
        //printf("%lld\n",p[0].x);
        for(int i = 0;i<n;i++){
            ans+=max(p[i].x,0ll);

        }
    
        LL res=1e18;
        for(int i = 0;i<n;i++){
            LL tmp=ans-max(p[i].x,0ll);
            tmp+=p[i].x+p[(i-1+n)%n].y;
            res=min(res,tmp);
           // printf("%lld\n",tmp);
        }
        printf("%lld\n",res);
    }
}
/*

*/