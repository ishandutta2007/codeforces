#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

template<int MN, int MM, typename F>
struct MaxFlow // dinics
{
	public:
		int N, hd[MN], to[MM*2], nx[MM*2], l[MM*2], M, S, T, q[MN], Q, cur[MN];
		F cap[MM*2], flow[MM*2];
		void init(int _N)
		{
			N = _N;
			memset(hd, -1, N*sizeof*hd);
		}
	private:
		void add1(int u, int v, F f)
		{
			nx[M] = hd[u];
			hd[u] = M;
			cap[M] = f;
			flow[M] = 0;
			to[M] = v;
			++M;
		}
	public:
		void adde(int u, int v, F cap) // one directional
		{
			add1(u, v, cap);
			add1(v, u, 0);
		}
		bool bfs()
		{
			q[Q=0]=S;
			memset(l, -1, N*sizeof*l);
			l[S]=0;
			for(int i=0;i<=Q;++i)
			{
				int n = q[i];
				for(int id=hd[n];~id;id=nx[id])
					if(l[to[id]] == -1 && cap[id] - flow[id] > 0)
					{
						l[to[id]] = l[n]+1;
						q[++Q] = to[id];
					}
			}
			return l[T] != -1;
		}
		F dfs(int n, F f)
		{
			if(n == T) return f;
			for(int& id=cur[n];~id;id=nx[id])
				if(l[to[id]] == l[n] + 1 && cap[id] - flow[id] > 0)
				{
					F pf = dfs(to[id], std::min(f, cap[id] - flow[id]));
					if(pf > 0)
					{
						flow[id] += pf;
						flow[id^1] -= pf;
						return pf;
					}
				}
			return 0;
		}
		F saturate(int _S, int _T)
		{
			S=_S, T=_T;
			F ans=0;
			for(;bfs();)
			{
				memcpy(cur, hd, N*sizeof*hd);
				for(F x;(x = dfs(S, std::numeric_limits<F>::max())) > 0;)
					ans += x;
			}
			return ans;
		}
};

const int MN = 3e3+10;
const int MV = 105;
const int INF = 0x3f3f3f3f;

int N, a[MN], b[MN], prev[MN];
std::vector<int> dv[MV];
MaxFlow<2+MN, MN + MN * 12, int> mf;

int main()
{
	for(int i=1;i<MV;++i)
		for(int j=i;j<MV;j+=i)
			dv[j].push_back(i);
	scanf("%d", &N);
	for(int i=0;i<N;++i) scanf("%d", a+i);
	for(int i=0;i<N;++i) scanf("%d", b+i);
	
	mf.init(N+2);

	memset(prev, 0xff, sizeof prev);
	int ans = 0;
	for(int i=0;i<N;++i)
	{
		if(b[i] > 0)
		{
			ans += b[i];
			mf.adde(N, i, b[i]);
		}
		if(b[i] < 0)
			mf.adde(i, N+1, -b[i]);
		for(int x:dv[a[i]])
			if(prev[x] != -1)
				mf.adde(i, prev[x], INF);
		prev[a[i]] = i;
	}

	printf("%d\n", ans - mf.saturate(N, N+1));
	return 0;
}