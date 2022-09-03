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
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int main() {
    LL b,d,s;
    scanf("%lld %lld %lld",&b,&d,&s);
    LL Min=min(b,min(d,s));
    b-=Min;
    d-=Min;
    s-=Min;
    LL ans=5e18;
    for(int i = 0;i<=1;i++)
        for(int j =0;j<=1;j++)
            for(int k = 0;k<=1;k++){
                LL Max=max(b-i,max(d-j,s-k));
                ans=min(ans,Max-(b-i)+Max-(d-j)+Max-(s-k));
            }
    printf("%lld\n",ans);
    return 0;
}