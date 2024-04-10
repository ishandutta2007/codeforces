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
    int n;
    scanf("%d",&n);
    while(n--){
        LL p,q,b;
        scanf("%lld %lld %lld",&p,&q,&b);
        LL gcd=__gcd(p,q);
        q/=gcd;
        LL x;
        while(__gcd(q,b)!=1){
            x=__gcd(q,b);
            while(q%x==0)
            q/=x;
            b=x;
        }
        if(q==1)
        printf("Finite\n");
        else
        printf("Infinite\n");
    }
}