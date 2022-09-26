#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 500005;

int n,m,tot;
int a[MAXN];
int b[MAXN];
int posa[MAXN << 1];
int posb[MAXN << 1];

ll k,N;
ll evt[MAXN << 1];

void exgcd(ll a,ll b,ll &x,ll &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(b,a % b,y,x);
	y -= a / b * x;
}

ll getinv(ll a,ll b)
{
	ll x,y;
	exgcd(a,b,x,y);
	return ((x % b) + b) % b;
}

void excrt(ll &m1,ll &c1,ll m2,ll c2)
{
	ll g = __gcd(m1,m2);
	if ((c2 - c1) % g != 0)
	{
		m1 = c1 = -1;
		return;
	}
	c1 = ((c2 - c1) / g * getinv(m1 / g,m2 / g)) % (m2 / g) * m1 + c1;
	m1 = m1 / g * m2;
	c1 = (c1 % m1 + m1) % m1;
}

ll getangry(ll d)
{
	ll ans = d;
	ans -= tot * (d / N);
	d -= d / N * N;
	for (int i = 1;i <= tot;i++)
		if (evt[i] < d)
			ans--;
	return ans;
}

int main()
{
	scanf("%d%d%lld",&n,&m,&k);
	memset(posa,-1,sizeof(posa));
	memset(posb,-1,sizeof(posb));
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		posa[a[i]] = i - 1;
	}
	for (int i = 1;i <= m;i++)
	{
		scanf("%d",&b[i]);
		posb[b[i]] = i - 1;
	}
	N = (ll)n / __gcd(n,m) * m;
	for (int i = 1;i <= 2 * max(n,m);i++)
		if (~posa[i] && ~posb[i])
		{
			ll m1 = n,m2 = m,c1 = posa[i],c2 = posb[i];
			excrt(m1,c1,m2,c2);
			if (~m1)
				evt[++tot] = c1;
		}
	sort(evt + 1,evt + tot + 1);
	ll low = 0,high = 1e18;
	while (low < high)
	{
		ll mid = low + high >> 1;
		if (getangry(mid) < k)
			low = mid + 1;
		else
			high = mid;
	}
	printf("%lld\n",low);
	return 0;
}