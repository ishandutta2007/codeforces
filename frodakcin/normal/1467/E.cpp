#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

const int MN = 2e5+10;
int N, a[MN], p[MN][20], d[MN], pre[MN], post[MN], ctr;
std::vector<int> b[MN], g[MN];

int fail()
{
	return printf("0\n"), 0;
}

struct BIT: public std::vector<int>
{
	public:
		BIT(int _sz): vector(_sz, 0) {}
		void upd(int n, int v)
		{
			assert(0 <= n && n <= size());
			for(++n;n<=size();n+=-n&n)
				 at(n-1) += v;
		}
		void upd(int l, int r, int v)
		{
			upd(l, v);
			upd(r, -v);
		}
		int qry(int n)
		{
			assert(0 <= n && n <= size());
			int f=0;
			for(;n;n-=-n&n)
				f += at(n-1);
			return f;
		}
};

void compress(int *a, int L)
{
	std::vector<int> x(a, a+L);
	std::sort(x.begin(), x.end());
	x.resize(std::distance(x.begin(), std::unique(x.begin(), x.end())));
	for(int i=0;i<L;++i)
		a[i] = std::distance(x.begin(), std::lower_bound(x.begin(), x.end(), a[i]));
}

void dfs(int n=1)
{
	pre[n] = ctr++;
	for(int i=0;p[n][i] && p[p[n][i]];++i)
		p[n][i+1] = p[p[n][i]][i];
	for(int x:b[n])
		if(p[n][0] != x)
		{
			d[x]=d[n]+1;
			p[x][0]=n;
			dfs(x);
		}
	post[n] = ctr;
}

int mu(int n, int x)
{
	for(int i=0;x;++i, x>>=1)
		if(x&1)
			n = p[n][i];
	return n;
}

bool anc(int a, int b)
{
	return pre[a] <= pre[b] && post[b] <= post[a];
}

int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;++i)
		scanf("%d", a+i);
	compress(a+1, N);
	for(int i=1;i<=N;++i)
		g[a[i]].push_back(i);
	for(int i=0;i+1<N;++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		b[u].push_back(v);
		b[v].push_back(u);
	}

	dfs();
	BIT bit(N);

	auto upd =[&](int n, int x)
	{
		if(p[n][0] == x)
			bit.upd(pre[n], post[n], 1);
		else if(p[x][0] == n)
			bit.upd(0, pre[x], 1), bit.upd(post[x], N, 1);
		else assert(0);
	};

	for(int i=0;i<N;++i)
		if(g[i].size() >= 2)
		{
			std::sort(g[i].begin(), g[i].end(), [&](int u, int v){return pre[u] < pre[v];});
			for(int j=0;j<g[i].size();++j)
			{
				int n = g[i][j];
				bool hasc = j+1<g[i].size() && anc(n, g[i][j+1]);
				bool hasp = j>0 || !anc(g[i][0 /* j is 0 */], g[i].back());
				assert(hasc || hasp);
				if(hasc && hasp)
					return fail();
				if(hasp) upd(n, p[n][0]);
				else
				{
					auto move_below = [&](int k) {return mu(k, d[k]-d[n]-1);};
					assert(j == 0);
					int c1 = move_below(g[i][1]);
					int c2 = move_below(g[i].back());
					if(c1 != c2) return fail();
					upd(n, c1);
				}
			}
		}

	int ans=0;
	for(int i=1;i<=N;++i)
		ans += bit.qry(pre[i]+1) == 0;
	printf("%d\n", ans);
	return 0;
}