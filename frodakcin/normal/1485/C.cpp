#include <cstdio>
#include <cassert>

using ll = long long;

int get(int x)
{
	int l=0, r=x+1;
	for(;r-l>1;)
	{
		int m=l+(r-l)/2;
		if(x/(m+1)<m)
			r=m;
		else
			l=m;
	}
	return r; // first where x/(r+1) < r
}

void solve()
{
	ll f=0;
	int x, y;
	scanf("%d%d", &x, &y);
	if(x<=y) y=x-1;
	++y;
	int m=get(x);
	if(y<=m) m=y;
	f += (ll)(m-1)*(m-2)/2; //add x-1 for x in [1, m)

	for(;m<y;)
	{
		int v=x/(m+1);
		if(v<1) break;
		int h=x/v;
		assert(x/(h+1) < v && x/h == v);

		if(y<h) h=y;
		f += (ll)(h-m)*v; // add [m, h)
		m=h;
	}

	printf("%lld\n", f);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}