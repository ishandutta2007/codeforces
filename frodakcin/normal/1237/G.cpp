#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
//#define NDEBUG
#include <cassert>

const int MN = 1e5 + 100;

int l2(int x)
{
	return 31 - __builtin_clz(x);
}
int N, K, A, a[MN], p[MN*2], x[MN], X, l[MN*2], q[MN*2][20], F, C;
std::vector<int> v[MN];

int md(int x) {
	if(x<N) return x;
	if((x-=N)<N) return x;
	return x%N;
}
void solve(int p, int e = 0)
{
	int s = 0;
	if(p+K > F+N)
	{
		int k = F+N-p;
		for(int i = 0;i < k;++i)
			s += a[md(p+i)];
		assert(s==k*A+e);
		printf("%d ", p%N);
		printf("%d ", a[md(p)] = A+e);
		for(int i = 1;i < k;++i)
			printf("%d ", a[md(p+i)] = A);
		for(int i = k;i < K;++i)
			printf("%d%c", a[md(p+i)], " \n"[i+1==K]);
		return;
	}
	for(int i = 0;i < K;++i)
		s += a[md(p+i)];
	if((s -= A*(K-1) + e) < 0)
		solve(p+K-1, -(s-=a[md(p+K-1)])), s += a[md(p+K-1)];
	printf("%d ", p%N);
	printf("%d ", a[md(p)] = A+e);
	for(int i = 1;i < K-1;++i)
		printf("%d ", a[md(p+i)] = A);
	printf("%d\n", a[md(p+K-1)] = s);
}

int main(void)
{
	memset(l, -1, sizeof(l));
	memset(q, -1, sizeof(q));
	scanf("%d%d", &N, &K);
	C = N;
	for(int i = 0;i < N;++i) scanf("%d", a+i), A+=a[i];
	A/=N;
	for(int i = 0;i < N;++i) p[i+1] = p[i]+a[i]-A, x[i] = p[i+1];
	std::sort(x, x+N);
	X = std::unique(x, x+N)-x;
	for(int i = 0;i < N;++i)
		p[i] = std::lower_bound(x, x+X, p[i])-x, v[p[i]].push_back(i);//cut from i-1 -> i
	for(int y = 0, V;y < X;++y)
	{
		std::vector<int> &v = ::v[y];
		V = v.size();
		for(int i = 0;i < V;++i) v.push_back(v[i]+N);
		for(int i = v.size()-1;i >= 0;--i)
		{
			q[i][0] = l[(v[i]+1)%(K-1)];
			for(int j = 0;~q[i][j]&&~q[q[i][j]][j];++j)
				q[i][j+1] = q[q[i][j]][j];
			l[v[i]%(K-1)] = i;
		}
		for(int i = 0, n, c;i < V;++i)
		{
			n = i, c = 0;
			for(int j = l2(V), k;j >= 0;--j)
				if(~q[n][j] && (k=q[n][j])<i+V)
					c += (v[k]-v[n]-(1<<j))/(K-1), n = k;
			c += (v[i]+N-v[n]+K-3)/(K-1);
			if(c < C || !(C < c) && v[i] < F)
				C = c, F = v[i];
		}
		for(int i = 0;i < v.size();++i)
			for(int j = 0;~q[i][j];++j)
				q[i][j] = -1;
		for(int x : v)
			l[x%(K-1)] = -1;
	}

	printf("%d\n", C);
	for(int i = F;i < F+N;++i)
		if(a[md(i)] != A)
			solve(i);
	return 0;
}