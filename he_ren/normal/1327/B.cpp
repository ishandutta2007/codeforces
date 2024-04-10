#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int a[MAXN];
vector<int> g[MAXN];
bool vis[MAXN],ok[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i]);
		g[i].resize(a[i]);
		for(int j=0; j<a[i]; ++j) scanf("%d",&g[i][j]);
	}
	
	for(int i=1; i<=n; ++i)
		vis[i]=ok[i]=0;
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<a[i]; ++j)
			if(!vis[g[i][j]])
			{
				vis[g[i][j]]=ok[i]=1;
				break;
			}
	}
	
	for(int i=1; i<=n; ++i)
	{
		if(ok[i] || a[i]==n) continue;
		for(int j=1; j<=n; ++j)
			if(!vis[j])
			{
				printf("IMPROVE\n%d %d\n",i,j);
				return;
			}
	}
	printf("OPTIMAL\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}