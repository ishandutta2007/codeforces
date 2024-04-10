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
#define MXN 200005
LL fra[300005];
int main(){ 
    int n,mod;
    scanf("%d %d",&n,&mod);
    fra[0]=1;
    for(int i = 1;i<=n;i++)
        fra[i]=fra[i-1]*i%mod;
    LL ans=0;
    for(int i = 1;i<=n;i++){
        ans+=(LL)(n-i+1)*fra[n-i+1]%mod*fra[i];
        ans%=mod;
    }
    printf("%lld\n",ans);
}