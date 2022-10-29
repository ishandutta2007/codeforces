#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second

const int MC = 8;
ll mods[MC];
ll vals[MC];
int rnd()
{
	return (int)((ll)rand() ^ ((ll)rand() << 14) & ll((1<<30)-1));
}

int getmod(ll x, ll mod)
{
	if (x < 0) x += ll(-x/mod)*(ll)mod + (ll)mod;
	if(x < 0ll)
	{
		cerr << x << ' ' << mod << endl;
		assert(false);
	}
	return (int)(x % (ll)mod);
}

ll modpow(ll a, ll p, ll mod)
{
	ll ans = 1ll;
	ll u = a;
	while (p)
	{
		if (p & 1ll) ans = (ans * u) % mod;
		u = (u * u) % mod;
		p >>= 1;
	}
	return ans;
}

ll gcd (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int a[200005];


int main()
{
	//srand(time(0));
	int n,k;
	scanf("%d%d", &n, &k);
	n++;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < MC; i++)
	{
		mods[i] = rnd() % (int)1e8 + 3;
		for (;;mods[i]++)
		{
			bool ok = 1;
			for (int j = 2; j*j <= mods[i] && ok; j++)
			   if (mods[i] % j == 0) ok = 0;
			if (ok) break;
		}
	}
	//cerr << "!!" << endl;
	for (int mod = 0; mod < MC; mod++)
	{
		vals[mod] = 0;
		ll two = 1;
		for (int i = 0; i < n; i++)	
		{	
			vals[mod] = (vals[mod] + two * getmod((ll)a[i], mods[mod])) % mods[mod];
			two = (two * 2) % mods[mod];
	    }		
	}
	/*for (int i = 0; i < MC; i++) cout << vals[i] << ' ';
	cout << endl;
	for (int i = 0; i < MC; i++) cout << mods[i] << ' ';
	cout << endl;*/
	
	//cerr << "!!!" << endl;
	int ans = 0;
	int MAGIC = 13;
	ll two[MC], rtwo[MC];
	for (int i = 0; i < MC; i++) {two[i] = getmod(2, mods[i]); rtwo[i] = modpow(two[i], mods[i]-2, mods[i]);}
	ll ctwo[MC], crtwo[MC];
	for (int i = 0; i < MC; i++) ctwo[i] = crtwo[i] = 1;
	for (int i = 0; i < n; i++)
	{
		bool ok = 1;
		//cout << "i=" << i << endl;
		ll d[MC];
		for (int j = 0; j < MC; j++)
		{
			int m1 = j;
			ll rval1 = (vals[m1] - ctwo[m1] * getmod(a[i], mods[m1]) % mods[m1] + mods[m1]) % mods[m1];
			d[j] = rval1 * crtwo[m1] % mods[m1];			
		}
		for (int j = 0; j < MAGIC; j++)
		{
			int m1 = rand() % MC, m2 = rand() % MC;
			if (m1 == m2) {m2 = (m1 + 1) % MC;}
			ll d1 = d[m1];
			ll d2 = d[m2];
			ll x,y;
			gcd(mods[m1], mods[m2], x, y);
			x *= (ll)(d2-d1);
			y *= (ll)(d2-d1);
			x = getmod(x, mods[m2]);
			y = getmod(y, mods[m1]);
			ll u = x*mods[m1] + d1;
			//cerr << x << ' ' << y << endl;
			assert(getmod(u, mods[m1]) == d1 && getmod(u, mods[m2]) == d2);
			ll u2 = u - mods[m1] * mods[m2];
			if ((max(u,-u) > (ll)k && max(u2,-u2) > (ll)k) || (i == n-1 && u == 0)) 
			{
				//cout << "d = " << d1 << ' ' << d2 << endl;
			
				//cout << "!!! " << u << ' ' << u2 << endl;
				
				ok = 0;
			}
			else
			{
				//cout << u << ' ' << u2 << endl;
			}
		}
		if (ok) 
		{
			//cout << "OK" << endl;
			ans++;
		}
		for (int j = 0; j < MC; j++)
		{
			ctwo[j] = (ctwo[j] * two[j]) % mods[j];
			crtwo[j] = (crtwo[j] * rtwo[j]) % mods[j];
		}   
	}
	cout << ans << endl;
	//cerr << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}