#include<cstdio>
#include<cmath>
const int MAXN = 1e5 + 5;
const int MAXM = 316 + 5;

int a[MAXN];
int dp[MAXN][MAXM+5];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int m=sqrt(n);
	for(int i=n; i>=1; --i)
		for(int j=1; j<=m; ++j)
		{
			if(i+a[i]+j>n) dp[i][j]=1;
			else dp[i][j] = dp[i+a[i]+j][j]+1;
		}
	
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int p,k;
		scanf("%d%d",&p,&k);
		if(k<=m) printf("%d\n",dp[p][k]);
		else
		{
			int ans=0;
			while(p<=n)
			{
				++ans;
				p+=a[p]+k;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}