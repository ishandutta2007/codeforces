#include <cstdio>
#include <algorithm>
#include <cassert>

using ll = long long;

int gcd(int a, int b)
{
	while(a)
	{
		b %= a;
		std::swap(a, b);
	}
	return b;
}

int pow(int b, int p, ll mod)
{
	int r=1;
	for(;p;p>>=1,b=(ll)b*b%mod)
		if(p&1)
			r=(ll)r*b%mod;
	return r;
}

struct Result
{
	public:
		int g;
		ll x, y;
};
Result egcd(int n, int m)
{
	if(n == 0)
		return {m, 0, 1};
	int v=m/n;
	auto const& res=egcd(m-v*n, n);

	return {res.g, res.y - v*res.x, res.x};
}
ll modinv(int n, int m)
{
	auto const& res=egcd(n, m);
	assert(res.g == res.x * n + res.y * m);
	return (res.x % m+m)%m;
}

void solve()
{
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	int x = a|b;

	// x mod 2^30
	// 0 mod d
	
	int g = gcd(d, 1<<30);
	if(x % g)
		return (void)printf("-1\n");
	x /= g;
	d /= g;

	ll v=x;
	if(d>1)
	{
		ll minv = modinv(1<<30, d);
		assert(minv < d);
		assert((minv << 30)%d == 1);
		//minv<<30 = 1 mod d
		v += (-(x%d)*minv%d+d) << 30;
	}

	printf("%lld\n", (ll)v * g);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}