#include <cstdio>
#include <cassert>
#include <vector>

const int MN = 1e5 + 100;
int N, M;
std::vector<int> a[MN];
struct loc
{
public:
	int n, t;
};
std::vector<loc> ans;
void add(int n, int t) {ans.push_back({n, t});};
void dfs(int n, int p, int e)
{
	add(n, e);
	int c = e;
	int cn = a[n].size() - !!p;
	for(int x : a[n])
		if(x != p)
		{
			if(c == M)
				add(n, c = M-cn-1);//e-(cn-(M-e))-1
			dfs(x, n, ++c);
			add(n, c);
		}
	if(e)
	{
		assert(c >= e-1);
		if(c != e-1)
			add(n, e-1);
	}
}
int main(void)
{
	scanf("%d", &N);
	if(N == 1) return printf("1\n1 0\n"), 0;
	for(int i = 0, u, v;i+1 < N;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	M = 2;
	for(int i = 1;i <= N;++i)
		 M = std::max(M, (int)a[i].size());
	dfs(1, 0, 0);
	printf("%d\n", ans.size());
	for(loc x : ans)
		printf("%d %d\n", x.n, x.t);
	return 0;
}