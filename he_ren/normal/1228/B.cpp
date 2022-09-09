#include<cstdio>
typedef long long ll;
const int MAXN = 1e3 + 5;
const int mod = 1e9 + 7;

int a[MAXN],b[MAXN],vis[MAXN][MAXN],ans[MAXN][MAXN];

inline int pw(int a,int b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=(ll)a*a%mod;
		b>>=1;
	}
	return (int)ans;
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i]);
		for(int j=1; j<=a[i]; ++j)
		{
			vis[i][j]=1;
			ans[i][j]=1;
		}
		vis[i][a[i]+1]=1;
	}
	for(int j=1; j<=m; ++j)
	{
		scanf("%d",&b[j]);
		for(int i=1; i<=b[j]; ++i)
		{
			if(vis[i][j]&&!ans[i][j])
			{
				printf("0");
				return 0;
			}
			vis[i][j]=1;
			ans[i][j]=1;
		}
		if(ans[b[j]+1][j])
		{
			printf("0");
			return 0;
		}
		vis[b[j]+1][j]=1;
	}
	
	int cnt=0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(!vis[i][j]) ++cnt;
	
	printf("%d",pw(2,cnt));
	return 0;
}