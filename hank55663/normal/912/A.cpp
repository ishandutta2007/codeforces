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
    LL a,b;
    scanf("%lld %lld",&a,&b);
    LL x,y,z;
    scanf("%lld %lld %lld",&x,&y,&z);
    LL needa=x*2+y;
    LL needb=z*3+y;
    LL ans = max(0ll,needa-a)+max(0ll,needb-b);
    printf("%lld\n",ans);
}