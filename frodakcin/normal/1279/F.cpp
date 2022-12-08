#include <cstdio>
#include <algorithm>
#define NDEBUG
#include <cassert>

const int MN = 1e6 + 100;

int N, K, L;
bool a[MN];
int p[MN];

struct state
{
public:
	int k, v;
	state(int k = 0, int v = 0) : k(k), v(v) {}
	bool operator < (state o) const {return v < o.v || !(o.v < v) && k > o.k;}
	state operator + (int dv) const {return {k+1, v+dv};}
};
state dp[MN];
int base, l, h;
int C;
void dodp()
{
	for(int i = 0;i < L;++i)
		dp[i] = {0,0};
	for(int i = L;i <= N;++i)
		dp[i] = std::max(dp[i-1], dp[i-L] + (p[i]-p[i-L]-C));
}
int solve()
{
	base = 0;
	for(int i = 0;i < N;++i)
		p[i+1] = p[i] + a[i], base += !a[i];
	l = -1, h = L;
	for(;l+1<h;)
	{
		C = l + (h-l)/2;
		dodp();
		if(K < dp[N].k) l = C;
		else h = C;
	}
	C = h;
	dodp();
	assert(dp[N].k <= K);
	return N-(base + dp[N].v + K*C);
}
void flip()
{
	for(int i = 0;i < N;++i)
		a[i]^=1;
}
int upper, lower;
int main(void)
{
	scanf("%d%d%d", &N, &K, &L);
	for(int i = 0;i < N;++i)
	{
		char q;
		scanf(" %c", &q);
		a[i] = q < 'a';
	}
	if(K>(N-1)/L) return printf("0\n"), 0;
	lower = solve();
	flip();
	upper = solve();
	printf("%d\n", std::min(lower, upper));
	return 0;
}