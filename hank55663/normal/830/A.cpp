#include<stdio.h>
#include<map>
#include<set>
#include<queue>
#include<vector> 
#include<string>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
#define seg pair<pii,pii>
//#define M 1000005
#define pi 3.14159265359
#define rank Rank
using namespace std;
typedef long long LL;
	LL dp[1005][2005];
int main()
{
	int n,k,p;
	scanf("%d %d %d",&n,&k,&p);
	int a[1005];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int b[2005];
	for(int i=1;i<=k;i++)
	scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	MEM(dp);
	for(int i=1;i<1005;i++)
		for(int j=0;j<2005;j++)
			dp[i][j]=1e18;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=k;j++){
		
			dp[i][j]=min(dp[i][j-1],max(dp[i-1][j-1],(LL)abs(a[i]-b[j])+abs(p-b[j])));
		//		printf("%lld %lld %lld\n",i,j,dp[i][j]);
		}
	printf("%I64d\n",dp[n][k]);
}
/* 4 9 6 3 7 8 8 2 9 1
/* 0 7 1 7 7*/