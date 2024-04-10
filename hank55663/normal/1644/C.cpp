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
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL ans[5005];
void solve(){
    int n,x;
    scanf("%d %d",&n,&x);
    fill(ans,ans+n+1,-1e18);
    int a[5005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++){
        LL sum=0;
        for(int j = i;j<n;j++){
            sum+=a[j];
            ans[j-i+1]=max(ans[j-i+1],sum);
        }
    }
    for(int i=0;i<=n;i++){
        LL res=0;
      //  if(i!=0)res+=x;
        for(int j=1;j<=n;j++){
            res=max(res,ans[j]+min(j,i)*1ll*x);
        }
        printf("%lld ",res);
    }
    printf("\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}