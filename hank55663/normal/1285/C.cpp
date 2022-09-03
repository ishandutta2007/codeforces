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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500

int main(){
    LL x;
    scanf("%lld",&x);
    pll ans=mp(x,1);
    for(LL i = 1;i*i<=x;i++){
        if(x%i==0){
            LL a=x/i,b=i;
            if(__gcd(a,b)==1){
                ans=min(ans,mp(a,b));
            }
        }
    }
    printf("%lld %lld\n",ans.x,ans.y);
}