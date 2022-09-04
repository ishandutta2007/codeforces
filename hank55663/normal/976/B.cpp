#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
int main(){
    LL n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    if(k<n){
        printf("%lld 1\n",k+1);
    }
    else{
        k-=n;
        if(k/(m-1)%2==0)
        printf("%lld %lld\n",n-k/(m-1),1+k%(m-1)+1);
        else
        printf("%lld %lld\n",n-k/(m-1),m-k%(m-1));
    }
    return 0;
}