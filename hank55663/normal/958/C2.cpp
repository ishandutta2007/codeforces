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
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main() {
   int n,K,p;
   scanf("%d %d %d",&n,&K,&p);
   int ans[105];
   int a[20005];
   for(int i=1;i<=n;i++)
   scanf("%d",&a[i]);
   int dp[55][20005];
   MEM(dp);
   int sum=0;
   for(int i=1;i<=n;i++){
       sum+=a[i];
       sum%=p;
       dp[1][i]=sum;
    ///   printf("%d ",dp[1][i]);
   }
  // printf("\n");
   for(int i=2;i<=K;i++){
       for(int j=0;j<p;j++)
         ans[j]=-1e9;
       for(int j=i;j<=n;j++){
            int temp[105];
            for(int k=0;k<p;k++)
                temp[k]=ans[k];
            for(int k=0;k<p;k++)
                ans[(k+a[j])%p]=temp[k];
            ans[a[j]%p]=max(ans[a[j]%p],dp[i-1][j-1]);
            dp[i][j]=-1e9;
            for(int k=0;k<p;k++)
                dp[i][j]=max(dp[i][j],ans[k]+k);
           // printf("%d ",dp[i][j]);
       }
    //   printf("\n");
   }
   printf("%d\n",dp[K][n]);
}