#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int dp[5005][5005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[5005];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    sort(a,a+n);
    a[n]=2e9;
    for(int i=1;i<=k+1;i++){
        int r=0;
        for(int j=0;j<n;j++){
            while(a[j]+5>=a[r])r++;
            if(j!=0)
            dp[j][i-1]=max(dp[j][i-1],dp[j-1][i-1]);
            dp[r][i]=max(dp[r][i],dp[j][i-1]+r-j);
           // printf("%d ",dp[j][i-1]);
        }
        dp[n][i-1]=max(dp[n][i-1],dp[n-1][i-1]);
       // printf("\n");
    }
    printf("%d\n",dp[n][k]);
}