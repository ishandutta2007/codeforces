#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}

const int MK = 26;
const int MN = 1e5+10;

int T, N, adj[MK], id[MK];
char a[MN], b[MN];
std::vector<int> c[MK], d[MK], cur;
bool v[MK], dp[1<<MK];

void dfs(int n)
{
	v[n]=1;
	for(int x:c[n])
		if(!v[x])
			dfs(x);
	for(int x:d[n])
		if(!v[x])
			dfs(x);
	cur.push_back(n);
}

int main()
{
	scanf("%d", &T);
	for(;T--;)
	{
		scanf("%d", &N);
		scanf(" %s %s", a, b);
		for(int i=0;i<N;++i)
			if(a[i]!=b[i])
				c[a[i]-'a'].push_back(b[i]-'a'), d[b[i]-'a'].push_back(a[i]-'a');
		for(int i=0;i<MK;++i)
		{
			std::sort(c[i].begin(), c[i].end());
			c[i].resize(std::distance(c[i].begin(), std::unique(c[i].begin(), c[i].end())));
			std::sort(d[i].begin(), d[i].end());
			d[i].resize(std::distance(d[i].begin(), std::unique(d[i].begin(), d[i].end())));
		}
		memset(v, 0, sizeof v);
		int f=0;
		for(int i=0;i<MK;++i)
		{
			if(v[i]) continue;
			dfs(i);
			for(int j=0;j<cur.size();++j)
				id[cur[j]]=j;
			memset(adj, 0, cur.size()*sizeof*adj);
			for(int x:cur)
				for(int y:c[x])
					adj[id[x]]^=1<<id[y];
			memset(dp, 0, sizeof*dp<<cur.size());
			int l=0;
			for(int j=0;j<cur.size();++j)
				dp[1<<j]=1;
			for(int j=1;j<1<<cur.size();++j)
				if(dp[j])
				{
					ckmax(l, __builtin_popcount(j));
					for(int k=0;k<cur.size();++k)
						if(!(j&1<<k) && !(j&adj[k]))
							dp[j|1<<k]=1;
				}
			f+=(int)cur.size()*2-1-l;
			cur.clear();
		}
		printf("%d\n", f);
		for(int i=0;i<MK;++i)
			c[i].clear(), d[i].clear();
	}
	return 0;
}