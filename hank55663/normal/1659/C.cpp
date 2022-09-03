#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    LL a,b;
    scanf("%d %lld %lld",&n,&a,&b);
    int x[200005];
    x[0]=0;
    LL dp[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    LL ans=1e18;
    LL sum=0;
    for(int i = 1;i<=n;i++){
        sum+=(x[i]-x[i-1])*b;
        if(i!=n){
            sum+=(x[i]-x[i-1])*a;
        }
    }
    ans=sum;
    for(int i = n-2;i>=0;i--){
        sum-=(x[i+1]-x[i])*a;
        sum+=(x[i+1]-x[i])*b*(n-i-1);;
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
UKOKCUEUKCKPNKPKPDEUFUFJUFBFPDPBFIFP
*/