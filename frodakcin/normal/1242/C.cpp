#include <cstdio>
#include <map>
#include <vector>

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

const int MK = 18;
const int MV = 1e9 + 100;
int K, N[MK], M;
ll sum[MK];
ll A;
std::vector<int> a[MK];
struct T
{
public:
	T(int n = -1, int i = -1) : n(n), i(i) {}
	int n, i;
};
std::map<int, T> m;
T dp[1<<MK];
int F[MK][2];
int find(T n)
{
	std::map<int, T>::iterator it;
	T t;
	int st = a[n.n][n.i];
	int mask = 0;
	for(T x = n;;)
	{
		ll seek = A - sum[x.n] + a[x.n][x.i];
		mask |= 1<<x.n;
		if(seek < -MV || seek > MV) return -1;
		if(seek == st) return mask;
		it = m.find(ti(seek));
		if(it == m.end()) return -1;
		t = it->second;
		if(mask&1<<t.n) return -1;
		x = t;
	}
}
void solve(int mask)
{
	if(dp[mask].n == -2)
		solve(dp[mask].i), solve(dp[mask].i^mask);
	else
	{
		T n = dp[mask], t;
		std::map<int, T>::iterator it;
		for(T x = n;;)
		{
			int seek = ti(A - sum[x.n] + a[x.n][x.i]);
			it = m.find(ti(seek));
			t = it->second;
			F[t.n][0] = t.i;
			F[t.n][1] = x.n;
			x = t;
			if(x.n == n.n) break;
		}
	}
}
int main(void)
{
	scanf("%d", &K);
	M = (1<<K)-1;
	for(int i = 0;i < K;++i)
	{
		scanf("%d", N+i);
		a[i].assign(N[i], -1);
		for(int j = 0, x;j < N[i];++j)
		{
			scanf("%d", &x);
			a[i][j] = x;
			m.insert({x, T(i, j)});
			sum[i] += x;
		}
		A += sum[i];
	}
	if(A%K != 0)
		return printf("No\n"), 0;
	A/=K;
	for(int i = 0;i < K;++i)
		for(int j = 0;j < N[i];++j)
		{
			int m = find({i,j});
			if(!~dp[m].n)
				dp[m] = {i,j};
		}
	for(int i = 1;i+1 < 1<<K;++i)
		if(~dp[i].n)
			for(int j = M^i, k = j;k;k=(k-1)&j)
				if(~dp[k].n&&!~dp[i|k].n)
					dp[i|k] = {-2, i};
	if(!~dp[M].n)
		return printf("No\n"), 0;
	printf("Yes\n");
	solve(M);
	for(int i = 0;i < K;++i)
		printf("%d %d\n", a[i][F[i][0]], F[i][1]+1);
	return 0;
}