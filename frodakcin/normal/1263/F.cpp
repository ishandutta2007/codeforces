#include <cstdio>
#include <vector>
#include <algorithm>
#define NDEBUG
#include <cassert>

const int MN = 1e3 + 10;
const int INF = 1e9 + 3;

bool min(int * a, int b) {return b<*a?*a=b,1:0;}

int N, A[2];
std::vector<int> a[2][MN*2];

int d[2][MN*2];
int pre[2][MN*2];
int post[2][MN*2];
int v[2][MN*2];
int w[2][MN];
struct Q
{
public:
	Q(int n = -1, int d = -1) : n(n), d(d) {}
	int n, d;
	bool operator < (Q o) const {return d < o.d;}
	bool operator () () const {return ~n;}
};
Q q[2][MN*4][12];

void dfs(int i, int n)
{
	if(!a[i][n].empty())
		v[i][n] = N+1;
	for(int x : a[i][n])
		dfs(i, x), v[i][n] = std::min(v[i][n], v[i][x]);
	std::sort(a[i][n].begin(), a[i][n].end(), [&](int x, int y){return v[i][x] < v[i][y];});
}
int t;
void dfs2(int i, int n)
{
	post[i][n] = pre[i][n] = t++;
	q[i][post[i][n]][0] = {n, d[i][n]};
	for(int x : a[i][n])
		d[i][x] = d[i][n]+1, dfs2(i, x), q[i][post[i][n] = t++][0] = {n, d[i][n]};
}
void rmq(int i)
{
	for(int j = A[i]*2-2;j >= 0;--j)
		for(int k = 0;j+(1<<k) <= A[i]*2-2;++k)
			q[i][j][k+1] = std::min(q[i][j][k], q[i][j+(1<<k)][k]);
}
int get(int i, int x, int y)
{
	if(!x || !y) return 0;
	x = pre[i][x], y = pre[i][y];
	assert(x != y);
	if(y < x) std::swap(x, y);
	int d = 31 - __builtin_clz(y-x);
	return std::min(q[i][x][d], q[i][y-(1<<d)][d]).d;
}

int dp[MN][MN];
int main(void)
{
	scanf("%d", &N);
	for(int i : {0,1})
	{
		scanf("%d", A+i);
		for(int j = 2, u;j <= A[i];++j)
			scanf("%d", &u), a[i][u].push_back(j);
		for(int j = 1;j <= N;++j)
			scanf("%d", w[i]+j), v[i][w[i][j]] = j;
		dfs(i, 1);
		t = 0;
		dfs2(i, 1);
		assert(t == A[i]*2-1);
		rmq(i);
	}
	for(int i = 0;i <= N;++i)
		for(int j = 0;j <= N;++j)
			dp[i][j] = INF;
	dp[0][0] = 0;
	dp[1][0] = d[0][w[0][1]];
	dp[0][1] = d[1][w[1][1]];
	for(int i = 0;i < N;++i)
		for(int j = i+1;j < N;++j)
			if(i != j)
			{
				min(dp[i]+(j+1), dp[i][j] + d[1][w[1][j+1]] - get(1, w[1][j], w[1][j+1]));
				min(dp[j+1]+j, dp[i][j] + d[0][w[0][j+1]] - get(0, w[0][i], w[0][j+1]));
				min(dp[j+1]+i, dp[j][i] + d[0][w[0][j+1]] - get(0, w[0][j], w[0][j+1]));
				min(dp[j]+(j+1), dp[j][i] + d[1][w[1][j+1]] - get(1, w[1][i], w[1][j+1]));
			}
	int F = INF;
	for(int i = 0;i < N;++i)
		min(&F, dp[i][N]), min(&F, dp[N][i]);
	printf("%d\n", A[0]-1+A[1]-1-F);
	return 0;
}