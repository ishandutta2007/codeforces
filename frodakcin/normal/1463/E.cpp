#include <cstdio>
#include <vector>
#include <queue>

const int MN = 3e5+10;

int N, K, C, p[MN], nx[MN], pr[MN], id[MN], req[MN];
std::vector<int> a[MN], chain[MN], relax[MN], ans;

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=1;i<=N;++i)
		scanf("%d", p+i), a[p[i]].push_back(i);
	for(int i=0;i<K;++i)
	{
		int u,v; scanf("%d%d", &u, &v);
		nx[u]=v; pr[v]=u;
	}

	{
		int vis=0;
		for(int i=1;i<=N;++i)
			if(!pr[i]) // conduct chain
			{
				++C;
				for(int j=i;j;j=nx[j])
				{
					++vis;
					id[j]=C;
					chain[C].push_back(j);
					if(id[p[j]] != C)
					{
						++req[C];
						relax[p[j]].push_back(C);
					}
				}
			}
		if(vis<N)
			return printf("0\n"), 0;
	}

	chain[0].push_back(0);
	std::queue<int> q; q.push(0);
	for(;!q.empty();)
	{
		int t=q.front(); q.pop();
		for(int n:chain[t])
		{
			ans.push_back(n);
			for(int x:relax[n])
				if(!--req[x])
					q.push(x);
		}
	}

	if(ans.size() != N+1)
		return printf("0\n"), 0;
	for(int i=1;i<=N;++i)
		printf("%d%c", ans[i], " \n"[i==N]);
	//ans[0] is 0
	return 0;
}