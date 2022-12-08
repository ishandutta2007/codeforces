#include <cstdio>
#include <vector>
#include <algorithm>

using ll = long long;

const int MK = 2e5 + 100;
struct E
{
public:
	int n, w;
};
std::vector<E> a[MK*2];
int K;

ll B, G;
int s[MK*2], p[MK*2];
int dfs(int n)
{
	s[n] = 1;
	for(E x : a[n])
		if(x.n != p[n])
		{
			p[x.n] = n, s[n] += dfs(x.n);
			if(s[x.n]&1)
				G += x.w;
			B += 1LL*std::min(s[x.n], K*2-s[x.n])*x.w;
		}
	return s[n];
}

void solve(void)
{
	B = G = 0LL;
	scanf("%d", &K);
	for(int i = 0;i < 2*K-1;++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}
	dfs(1);
	for(int i = 1;i <= 2*K;++i)
		a[i].clear(), p[i] = 0;
	printf("%lld %lld\n", G, B);
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;++i)
		solve();
	return 0;
}