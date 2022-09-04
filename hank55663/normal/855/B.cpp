#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int main(){
	LL n,p,q,r;
	scanf("%I64d %I64d %I64d %I64d",&n,&p,&q,&r);
	int a[100005];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	LL dp[100005][3];
	MEM(dp);
	dp[0][0]=-3e18-1;
	dp[0][1]=-3e18-1;
	dp[0][2]=-3e18-1;
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],p*a[i]);
		dp[i][1]=max(dp[i-1][1],dp[i][0]+q*a[i]);
		dp[i][2]=max(dp[i-1][2],dp[i][1]+r*a[i]);
	//	printf("%I64d %I64d %I64d\n",dp[i][0],dp[i][1],dp[i][2]);
	}
	printf("%I64d\n",dp[n][2]);
}