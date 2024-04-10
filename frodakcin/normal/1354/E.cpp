#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <vector>

const int MN=5e3+10;
int N, M, n1, n2, n3, dp[MN][MN], ans[MN];
bool v[MN], c[MN];
std::vector<int> a[MN];
struct group
{
public:
	std::vector<int> n[2];
};
std::vector<group> cc;
void dfs(int n)
{
	v[n]=1;
	cc.back().n[c[n]].push_back(n);
	for(int x:a[n])
		if(!v[x])
		{
			c[x]=!c[n];
			dfs(x);
		}
		else
			if(c[x]==c[n])
			{
				printf("NO\n");
				exit(0);
			}
}
int main(void)
{
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &n1, &n2, &n3);
	for(int i=0,x,y;i<M;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	for(int i=1;i<=N;++i)
		if(!v[i])
		{
			cc.push_back(group());
			dfs(i);
			//printf("VALS: %u %u\n", cc.back().n[0].size(), cc.back().n[1].size());
		}
	memset(dp, -1, sizeof dp);
	dp[0][0]=0;
	for(int i=0;i<cc.size();++i)
		for(int j=0;j<=n2;++j)
			if(~dp[i][j])
			{
				for(int k=0;k<2;++k)
					if(j+cc[i].n[k].size() <= n2)
						dp[i+1][j+cc[i].n[k].size()]=j<<1|k;
			}
	if(!~dp[cc.size()][n2])
		return printf("NO\n"), 0;
	for(int i=cc.size(), j=n2;i;--i)
	{
		int v=dp[i][j];
		for(int k:cc[i-1].n[v&1^1])
			ans[k]=n3?--n3, 3:1;
		assert((v>>1) == j-cc[i-1].n[v&1].size());
		j=v>>1;
	}
	printf("YES\n");
	for(int i=1;i<=N;++i)
		if(ans[i])
			printf("%d", ans[i]);
		else printf("2");
	printf("\n");
	return 0;
}