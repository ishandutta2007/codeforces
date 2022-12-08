#include <cstdio>
#include <algorithm>

const int MN = 1e5 + 100;
const int INF = 1e9 + 100;
int T, N;
int mx;
int ans, dif;

void solve()
{
	mx = -INF;
	ans = 0, dif = 0;

	scanf("%d", &N);
	for(int i = 0;i < N;++i)
	{
		int x;
		scanf("%d", &x);
		if(x < mx)
			++ans, dif = std::max(dif, mx - x);
		else
			mx = x;
	}
	printf("%d\n", dif ? 32 -__builtin_clz(dif) : 0);
}
int main(void)
{
	scanf("%d", &T);
	for(;T--;)
		solve();
	return 0;
}