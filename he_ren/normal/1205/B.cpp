#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
typedef long long ll;
const int MAXN = 1e5 + 5;
const int lb = 60;
const int MAXP = lb*2 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;

inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

ll a[MAXN];
int cnt[lb];

int g[MAXP][MAXP];
ll dis[MAXP][MAXP];

int main(void)
{	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n;)
	{
		cin>>a[i];
		if(a[i]) ++i;
		else --n;
	}
	
	for(int j=0; j<lb; ++j)
	{
		for(int i=1; i<=n; ++i)
			if((a[i]>>j)&1)
			{
				++cnt[j];
				if(cnt[j]==3)
				{
					printf("3");
					return 0;
				}
			}
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			if(i!=j && a[i]&a[j]) dis[i][j]=g[i][j]=1;
			else dis[i][j]=g[i][j]=inf;
			
			if(i==j) dis[i][j]=0;
		}
	
	ll ans=inf;
	for(int k=1; k<=n; ++k)
	{
		for(int i=1; i<k; ++i)
			for(int j=1; j<i; ++j)
				chk_min(ans, dis[i][j] + g[i][k] + g[k][j]);
		
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				chk_min(dis[i][j], dis[i][k] + dis[k][j]);
	}
	
	if(ans==inf) printf("-1");
	else printf("%d",(int)ans);
	return 0;
}