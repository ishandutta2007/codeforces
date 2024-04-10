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
    int n;
    scanf("%d",&n);
    LL a[200005];
    a[0]=0;
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    LL Max=a[n];
    LL dp[200005];
    dp[n]=0;
    for(int i=n-1;i>=1;i--){
        dp[i]=Max;
        Max=max(a[i]-dp[i],Max);
    }
    printf("%lld\n",dp[1]);
    return 0;
}