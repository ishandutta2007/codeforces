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
#define MXN 1500
#define hash Hash
int mod=1e9+7;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int f[100005];
    f[0]=2;
    f[1]=4;
    for(int i = 2;i<100005;i++){
        f[i]=f[i-1]+f[i-2];
        f[i]%=mod;
    }
    LL ans=(f[n-1]+f[m-1]-2)%mod;
    printf("%lld\n",ans);
}