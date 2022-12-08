#include <cstdio>
#include <cassert>

using ll = long long;

int T;
ll N, l, r, c;
bool pos;

bool guess(ll v)
{
	printf("? %lld\n", v);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
void solve()
{
	scanf("%lld", &N);
	l=0, r=N;
	c=1;
	for(ll x=0;x+2<N;)
	{
		c -= x+N>>1;
		x=x+N>>1;
		assert(x+1<N);
		c += x+N>>1;
		x=x+N>>1;
	}
	guess(c);
	pos=1;
	for(;r-l>1;)
	{
		ll m=(l+r)/2;
		if(pos)
			c += m;
		else
			c -= m;
		if(guess(c))
			r=m;
		else
			l=m;
		pos ^= 1;
	}
	printf("= %lld\n", r);
	fflush(stdout);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}