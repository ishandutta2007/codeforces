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
#define next Next
int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    LL a[300005];
    a[0]=0;
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    LL val[300005];
    val[0]=0;
    LL ans=0;
    for(int i = 1;i<=m&&i<=n;i++){
        val[i]=0;
        for(int j  =0;j<i;j++){
            val[i]=max(val[i],a[i]-a[j]-k);
        }
        ans=max(val[i],ans);
    }
    for(int i = m+1;i<=n;i++){
        val[i]=0;
        for(int j  =i-m;j<i;j++){
            val[i]=max(val[i],a[i]-a[j]-k);
        }
        val[i]=max(val[i],val[i-m]+a[i]-a[i-m]-k);
        ans=max(ans,val[i]);
    }
    printf("%lld\n",ans);
}