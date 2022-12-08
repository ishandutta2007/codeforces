#include <cstdio>
#include <cmath>
#include <vector>

const int MN = 1e6+10;
int N, a[MN], match[MN], sz[MN], ans;
std::vector<int> b[MN], c[MN];
int vis[MN], col[MN];

int dfs(int n)
{
	vis[n]=1;
	sz[n]=1;
	for(int x:c[n])
		if(!vis[x])
			col[x]=-col[n], sz[n]+=dfs(x);
	if(col[n] > 0) ans += n;
	ans %= N*2;
	return sz[n];
}

int main()
{
	scanf("%d", &N);
	if(!(N&1)) //even
	{
		printf("First\n");
		for(int i=0;i<N;++i) printf("%d ", i+1);
		for(int i=0;i<N;++i) printf("%d%c", i+1, " \n"[i+1==N]);
		fflush(stdout);
	}
	else
	{
		printf("Second\n");
		fflush(stdout);
		for(int i=1;i<=2*N;++i)
			scanf("%d", a+i), b[a[i]].push_back(i);
		bool ok=0;
		for(int i=1;i<=N;++i)
		{
			int u=b[i][0], v=b[i][1];
			match[u]=v, match[v]=u;
			c[u].push_back(v), c[v].push_back(u);
			c[i].push_back(i+N);
			c[i+N].push_back(i);
		}
		int val=0, flip=-1;
		for(int i=1;i<=N*2;++i)
			if(!vis[i])
			{
				col[i]=++val;
				if(dfs(i)%4 == 2)
					flip=col[i];
			}
		if(ans % (N*2))
		{
			for(int i=1;i<=2*N;++i)
				if(std::abs(col[i]) == flip) col[i]*=-1;
		}
		for(int i=1, f=0;i<=N*2;++i)
			if(col[i]>0)
			{
				if(f) printf(" ");
				f=1;
				printf("%d", i);
			}
		printf("\n");
		fflush(stdout);
	}
	scanf("%*d");
	return 0;
}