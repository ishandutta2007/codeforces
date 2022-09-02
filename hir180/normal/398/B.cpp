#include <cstdio>
#include <algorithm>
using namespace std;
double dp[2005][2005];
bool used[2005];
bool used2[2005];
int n,m;
double calc(int remx,int remy)
{
	if(remx+remy==0) return dp[remx][remy]=0.0;
	if(dp[remx][remy]) return dp[remx][remy];
	double &res=dp[remx][remy];
	res+=1.0;
	if(remx) res+=(double)remx*(n-remy)/(double)(n*n)*calc(remx-1,remy);
	if(remy) res+=(double)remy*(n-remx)/(double)(n*n)*calc(remx,remy-1);
	if(remx && remy) res+=(double)remx*remy/(double)(n*n)*calc(remx-1,remy-1);
	res*=(double)n*n/(double)(n*n-(n-remy)*(n-remx));
	return res;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		--x; --y;
		used[x]=used2[y]=true;
	}
	int cnt=count(used,used+n,0);
	int cnt2=count(used2,used2+n,0);
	printf("%.10f\n",calc(cnt,cnt2));
}