#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

const int MN = 1e3+10;
const int K = 20;

int N, M, T, id[MN], t[MN], ctr, m[1<<K];
bool conn[MN][MN];
char s[10];
std::vector<int> a[MN], on[K+1];

struct Mod
{
	public:
		char c;
		int a,b;
		void out() const {printf("%c %d %d\n", c, a, b);}
};
std::vector<Mod> f;

void flip(int a, int b)
{
	f.push_back({conn[a][b]?'-':'+', a, b});
	conn[a][b]^=1;
}

void dfs(int n)
{
	for(int x:a[n])
		if(!~id[x])
			dfs(x);
	id[n]=ctr;
	t[ctr]=n;
	++ctr;
}

int main()
{
	memset(id, -1, sizeof id);
	scanf("%d%d%d", &N, &M, &T);
	for(int i=0,u,v;i<M;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), conn[u][v]=1;

	ctr=0;
	for(int i=1;i<=N;++i)
		if(!~id[i])
			dfs(i);
	for(int i=std::min(N, K)-1;i;--i)
		for(int j=i-1;j>=0;--j)
			if(!conn[t[i]][t[j]]) // create Dag out of first K nodes
			{
				a[t[i]].push_back(t[j]);
				conn[t[i]][t[j]]=1;
				f.push_back({'+', t[i], t[j]});
			}

	for(int i=0;i<1<<K;++i)
		if(__builtin_popcount(i)<=3)
			on[__builtin_popcount(i)].push_back(i);
	memset(m, -1, sizeof m);
	for(int i=K;i<N;++i)
	{
		f.push_back({'+', t[i], t[i]});
		int n=t[i], v=0;
		for(int x:a[n])
			if(id[x]<K)
				v|=1<<id[x];
		bool ok=0;
		for(int j=0;!ok;++j) // j should never exceed 3
		{
			assert(j <= 3);
			for(int k:on[j])
				if(!~m[v^k])
				{
					m[v^k]=n;
					for(int b=0;b<K;++b)
						if(k>>b&1)
							flip(n, t[b]);
					ok=1;
					break;
				}
		}
	}

	printf("%u\n", f.size());
	for(int i=0;i<f.size();++i) f[i].out();
	fflush(stdout);

	for(int i=0;i<T;++i)
	{
		int v=0;
		bool lose=0;
		for(int j=0;j<std::min(N,K);++j)
		{
			printf("? 1 %d\n", t[j]);
			fflush(stdout);
			scanf(" %s", s);
			if(s[0]=='S') return 0;
			if(s[0]=='W') v|=1<<j;
			if(s[0]=='L')
			{
				lose=1, v=j;
				break;
			}
		}
		if(lose) printf("! %d\n", t[v]);
		else printf("! %d\n", m[v]);
		fflush(stdout);
		scanf(" %s", s);
		if(s[0]=='W') return 0;
	}
	return 0;
}