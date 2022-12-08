#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>

template<typename T> bool ckmax(T& a, T b){return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, T b){return b<a?a=b,1:0;}

const int MN = 2e5+10;

int N, M, T, t[MN], ctr, d[MN];
bool v[MN];
std::vector<int> a[MN], f;

void dfs(int n)
{
	v[n]=1;
	for(int x:a[n])
		if(!v[x]) dfs(x);
	t[ctr++]=n;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &M);
		for(int i=0,x,y;i<M;++i)
		{
			scanf("%d%d", &x, &y);
			if(a[x].empty() || a[x][0] != y)
				a[x].push_back(y);
		}
		ctr=0;
		for(int i=1;i<=N;++i)
			if(!v[i])
				dfs(i);
		assert(ctr==N);

		for(int i=1;i<=N;++i) d[i]=1;
		std::reverse(t, t+N);
		for(int i=0,x;i<N;++i)
		{
			x=t[i];
			//printf("%d: %d %d\n", i, x, d[x]);
			if(!~d[x])
			{
				f.push_back(x);
				continue;
			}
			int v=d[x]-1;
			for(auto y:a[x])
				ckmin(d[y], v);
		}
		printf("%u\n", f.size());
		for(int i=0;i<f.size();++i)
			printf("%d%c", f[i], " \n"[i+1==f.size()]);

		memset(v+1, 0, N*sizeof*v);
		for(int i=1;i<=N;++i) a[i].clear();
		f.clear();
	}
}