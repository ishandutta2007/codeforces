#include <cstdio>
#include <algorithm>

using ll = long long;
const int MN = 55;
const int MA = 1e8 + 10;
const ll INF = 1e18;

bool ckmin(ll& a, ll b) {return b<a?a=b,1:0;}

int N;
ll P;
struct task
{
public:
	int n, d;
	ll val() const {return 1000LL*n-P*d;}
	bool operator < (task o) const {return n > o.n || !(o.n > n) && d > o.d;}
};
task a[MN];
ll dp[MN][MN];
ll p[MN];
ll f;
bool test()
{
	for(int i = 0;i < N;++i)
		p[i+1] = p[i] + a[i].val();
	for(int i = 0;i <= N;++i)
		for(int j = 0;j <= i;++j)
			dp[i][j] = INF;
	dp[0][0] = 0LL;
	for(int i = 0, j, K;i < N;i=j)
	{
		for(j=i+1;j<N && a[i].n==a[j].n;++j);
		K = j-i;
		for(int k = 0;k <= K;++k)
			for(int x = K-k;x <= i;++x)
				ckmin(dp[j][x+k*2-K], dp[i][x]+p[i+k]-p[i]);
	}
	f = 1;
	for(int i = 0;i <= N;++i)
		ckmin(f, dp[N][i]);
	return f <= 0;
}

ll l, h;
int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;++i)
		scanf("%d", &a[i].n);
	for(int i = 0;i < N;++i)
		scanf("%d", &a[i].d);
	std::sort(a, a+N);
	l = -1, h = 1000LL*MA;
	for(;l+1<h;)
	{
		P = l+(h-l)/2;
		if(test()) h = P;
		else l = P;
	}
	printf("%lld\n", h);
	return 0;
}