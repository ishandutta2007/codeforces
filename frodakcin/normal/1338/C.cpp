#include <cstdio>

using ll = long long;
ll val[16] = {0, 0, 0, 1, 2, 3, 2, 3, 1, 3, 1, 2};

ll N;
int type;
ll ans;
int T;

void solve()
{
	scanf("%lld", &N), --N;
	ans = 0;
	type = (int)(N%3);
	N /= 3;
	int i = 0;
	for(;N >= 1LL<<i*2;++i)
		N -= 1LL<<i*2;

	ans |= val[3+type]<<i*2;
	for(--i;i >= 0;--i)
	{
		int z = N>>2*i&3;
		ans |= val[z*3+type]<<i*2;
	}
	printf("%lld\n", ans);
}
int main(void)
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}