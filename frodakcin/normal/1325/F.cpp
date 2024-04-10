#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cassert>

template<class T> bool ckmax(T * a, T b) {return *a<b?*a=b,1:0;}
template<class T> bool ckmin(T * a, T b) {return b<*a?*a=b,1:0;}

const int MN = 1e5 + 100;
int N, M, d[MN], p[MN], C;
std::vector<int> a[MN], ans;
int dfs(int n)
{
	int l = d[n], l2 = N+10;
	for(int x : a[n])
		if(~d[x])
			ckmin(&l, d[x]);
		else
			p[x] = n, d[x] = d[n]+1, ckmin(&l2, dfs(x));
	if(d[n] - l + 1 >= C)
	{
		printf("2\n%d\n", d[n] - l + 1);
		for(int x = n;d[x] >= l;x = p[x])
			printf("%d%c", x, " \n"[d[x]==l]);
		exit(0);
	}
	if(d[n] < l2)
		return ans.push_back(n), l;
	return l2;
}

int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i = 0, u, v;i < M;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	memset(d, -1, sizeof(d[0])*(N+1));
	for(;C*C < N;++C);
	d[1] = 0;
	dfs(1);
	assert(ans.size() >= C);
	printf("1\n");
	for(int i = 0;i < C;++i)
		printf("%d%c", ans[i], " \n"[i+1==C]);
	return 0;
}