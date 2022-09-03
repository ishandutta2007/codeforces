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
#define MXN 10005
#define less Less
int main(){
    int n,p,k;
    scanf("%d %d %d",&n,&p,&k);
    map<LL,LL> m;
    LL ans=0;
    for(int i = 0;i<n;i++){
        LL x;
        scanf("%lld",&x);
        LL val=x*x%p*x%p*x%p-k*x%p;
       // printf("%lld %lld\n",val,x*x*x*x);
        val = (val%p+p)%p;
        ans+=m[val];
        m[val]++;
    }
    printf("%lld\n",ans);
}