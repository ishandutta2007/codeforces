//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define debug(...) (cerr<<"'"<<__FUNCTION__<<"': "),fprintf(stderr,__VA_ARGS__)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;

pair<int,int> p[5011];
int n;
double dis[2511][2511];
double dp[5011][2511][2];
#define cd(x,y) dis[(x)%n][(y)%n]
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&p[i].FF,&p[i].SS),p[i+n]=p[i];
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			dis[i][j]=dis[j][i]=sqrt(1ll*(p[i].FF-p[j].FF)*(p[i].FF-p[j].FF)+1ll*(p[i].SS-p[j].SS)*(p[i].SS-p[j].SS));
		}
	}
	double ans=0;
	for(int i=n+n-1;i>=0;i--)
	{
		for(int j=i+1;j<i+n&&j<n+n;j++)
		{
			int tj=j-i;
			if(i+1==j)dp[i][tj][0]=dp[i][tj][1]=cd(i,j);
			else
			{
				dp[i][tj][0]=max(dp[i+1][tj-1][0]+cd(i,i+1),dp[i+1][tj-1][1]+cd(i,j));
				dp[i][tj][1]=max(dp[i][tj-1][0]+cd(j,i),dp[i][tj-1][1]+cd(j,j-1));
//				dp[i][tj][0]+=cd(i,j);
//				dp[i][tj][1]+=cd(i,j);
			}
			if(j==i+n-1)
			{
				ans=max(ans,dp[i][tj][0]);
				ans=max(ans,dp[i][tj][1]);
			}
//			cerr<<i<<","<<j<<" "<<dp[i][tj][0]<<" "<<dp[i][tj][1]<<endl;
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}