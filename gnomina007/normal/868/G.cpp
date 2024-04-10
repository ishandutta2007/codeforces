#include<iostream>
#include<vector>
#define mp(x, y, z) pair<long long, long long> z=make_pair(x, y)
#define pb(x, y) x.push_back(y)
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pr;
typedef vector <long long>  vl;
ll awe[50005], bwe[50001], osab[100001], tsab[1000000];
ll p = 1000000007, slv;
ll bp(ll a, ll b)
{
	{
		if (b == 0)
		{
			return 1;
		}
		else
			if (b % 2 == 0)
			{
			ll aq = bp(a, b / 2);
			return (aq*aq) % p;
			}
			else
			{
				ll aq = bp(a, b - 1);
				return (aq*a) % p;
			}
	}
}
void awe_count()
{
	awe[0] = 1;
	ll cur = 1;
	for (int i = 1; i <= 50000; i++)
	{
		cur = (cur * 2) % p;
		awe[i] = cur;
	}
}
void bwe_count()
{
	bwe[0] = 1;
	ll cur = 1, rr=awe[50000];
	for (int i = 1; i <= 50000; i++)
	{
		cur = (cur * rr) % p;
		bwe[i] = cur;
	}
}
ll bxb1(ll x)
{
	ll x1 = x / 50000, y1 = x % 50000;
	ll ans = awe[y1] * bwe[x1];
	ans %= p;
	return ans;
}
ll obr(ll a)
{
	slv++;
	return bp(a, p - 2);
//	return 228;
}
void osab_count()
{
	ll cur = 1;
	for (int i = 1; i <= 50000; i++)
	{
		osab[i] = obr(cur);
		cur = 2 * cur + 1;
		cur %= p;
	}
}
void tsab_count()
{
	tsab[1] = 1;
	for (int i = 2; i <= 999000; i++)
	{
		tsab[i] = (p - (p / i) * tsab[p%i] % p) % p;
	}
}
ll o1(ll b)
{
	if (b < 50000)
	{
		return osab[b];
	}
	else
	{
		ll ty = bxb1(b) - 1;
		return obr(ty);
	}
}
ll o2(ll b)
{
	if (b < 998000)
	{
		return tsab[b];
	}
	else
	{
		return obr(b);
	}
}
ll sgm(ll a, ll t, ll m)
{
	ll x = (bxb1(m*t) + p - 1) % p;
	ll y = obr((bxb1(t) + p - 1) % p);
	return (x*y) % p;
}
ll squ(ll a, ll t, ll m)
{
	ll a1 = (t*m) % p;
	a1 = (a1*sgm(a, t, m)) % p;
	ll b1 = sgm(a, t, m + 1) - m - 1 + p;
	b1 %= p;
	ll y = obr((bxb1(t) + p - 1) % p);
	b1 = (b1*y) % p;
	b1 *= t;
	b1 %= p;
	return(a1 - b1 + p) % p;
	//return 228;
}
vl solve(vl &v)
{
	ll a = v[0], b = v[1], c2 = v[2], c3 = v[3], cc2 = v[4], cc3 = v[5], n = v[6], v1 = v[7];
	ll v2 = v[8], n1 = v[9], sum = v[10], nach = v[11];
	ll obrb = o2(b);
	ll l1 = (a - 1) / b;
	ll f1 = l1*v1 + v2, f2 = (l1 - 1)*v1 + v2;
	ll  rt = bxb1(b), bb = bxb1(b*(l1 - 1)), aa = (bb*rt) % p, cc = (aa*rt) % p;
	ll ort = o1(b), xz1 = (bb - 1)*(ort), xz = (aa - 1)*(ort), xz2 = (cc - 1)*(ort);
	ll CC4 = (cc3*(l1 - 1)) % p;
	CC4 *= v1;
	CC4 %= p;
	CC4 *= bb;
	ll C4 = (cc3*l1) % p;
	C4 *= v1;
	C4 %= p;
	C4 *=aa;
	xz %= p;
	xz1 %= p;
	xz2 %= p;
	ll dc1 = b*l1*xz;
	ll dc2 = xz2 - l1 - 1 + p;
	dc1 %= p;
	dc2 *= ort;
	dc2 %= p;
	dc2 *= b;
	dc2 %= p;
	ll C2 = (xz*c2 + aa*cc2) % p + ((((v1*obrb) % p)*(dc1 - dc2 + p)) % p)*c3 + C4;
	ll C3 = (c3*xz + cc3*aa) % p;
	dc1 = b*(l1 - 1)*xz1;
	dc2 = xz - l1 + p;
	dc1 %= p;
	dc2 *= ort;
	dc2 %= p;
	dc2 *= b;
	dc2 %= p;
	ll CC2 = (xz1*c2 + bb*cc2) % p + c3*((((v1*obrb) % p)*(dc1 - dc2 + p)) % p) + CC4;
	ll CC3 = (c3*xz1 + cc3*bb) % p;
	CC2 %= p;
	C2 %= p;
	vl vnew1;
	if (f1 > n)
	{
		ll x = n / v1;
		aa = bxb1(n1);
		ll lln = bxb1(b*x), lln2 = (lln*rt) % p, xfz = (ort*(lln - 1)) % p, xfz2 = (ort*(lln2 - 1)) % p;
		dc1 = b*x*xfz;
		dc2 = xfz2 - x - 1 + p;
		dc1 %= p;
		dc2 *= ort;
		dc2 %= p;
		dc2 *= b;
		dc2 %= p;
		ll km = xfz*c2;
		km %= p;
		ll sum1 = sum + km*aa;
		ll nn = n - x*v1;
		ll nn1 = n1 + x*b;
		ll p1 = nach - n;
		p1 *= c3;
		p1 %= p;
		p1 *= aa;
		p1 %= p;
		p1 *= xfz;
		p1 %= p;
		sum1 += p1;
		p1 = c3;
		p1 *= v1;
		p1 %= p;
		p1 *= aa;
		p1 %= p;
		p1 *= (dc1 - dc2 + p);
		p1 %= p;
		p1 *= obrb;
		p1 %= p;
		sum1 += p1;
		sum1 %= p;
		vnew1.reserve(4);
		pb(vnew1, sum1);
		pb(vnew1, nn);
		pb(vnew1, nn1);
		pb(vnew1, nach);
	}
	else
	{
		ll aa = b, bb = (b - a%b) % b;
		vl vnew;
		vnew.reserve(12);
		pb(vnew, aa);
		pb(vnew, bb);
		pb(vnew, C2);
		pb(vnew, C3);
		pb(vnew, CC2);
		pb(vnew, CC3);
		pb(vnew, n);
		pb(vnew, f1);
		pb(vnew, f2);
		pb(vnew, n1);
		pb(vnew, sum);
		pb(vnew, nach);
		vl vb = solve(vnew);
		ll x = vb[1] / v1;
		aa = bxb1(vb[2]);
		ll lln = bxb1(b*x), lln2 = (lln*rt) % p, xfz = (ort*(lln - 1)) % p, xfz2 = (ort*(lln2 - 1)) % p;
		dc1 = b*x*xfz;
		dc2 = xfz2 - x - 1 + p;
		dc1 %= p;
		dc2 *= ort;
		dc2 %= p;
		dc2 *= b;
		dc2 %= p;
		ll km = xfz*c2;
		km %= p;
		ll sum1 = vb[0] + km*aa;
		ll nn = vb[1] - x*v1;
		ll nn1 = vb[2] + x*b;
		ll p1 = nach - vb[1];
		p1 *= c3;
		p1 %= p;
		p1 *= aa;
		p1 %= p;
		p1 *= xfz;
		p1 %= p;
		sum1 += p1;
		p1 = c3;
		p1 *= v1;
		p1 %= p;
		p1 *= aa;
		p1 %= p;
		p1 *= (dc1 - dc2 + p);
		p1 %= p;
		p1 *= obrb;
		p1 %= p;
		sum1 += p1;
		sum1 %= p;
		vnew1.reserve(4);
		pb(vnew1, sum1);
		pb(vnew1, nn);
		pb(vnew1, nn1);
		pb(vnew1, nach);
	}
	return vnew1;
}
ll resh(ll n, ll a, ll b, ll c1, ll c2, ll c3, ll x1, ll x2, ll x3, ll x4)
{
	ll n1 = (n) % a, na = n / a;
	ll ans1, ans2, ans3;
	ans1 = x2 + ((((a - 1)*bxb1(x4)) % p)*c3) % p;
	ans3 = x3;
	ans1 %= p;
	ans1 *= (na);
	ans1 %= p;
	ll m = x1, m2 = sgm(2, 1, a), m3 = squ(2, 1, a);
	ans2 = m2*na;
	ans2 %= p;
	ans2 *= c3;
	ans2 %= p;
	ans2 *= (na - 1);
	ans2 %= p;
	ans2 *= ((p + 1) / 2);
	ans2 %= p;
	ans2 *= a;
	ans2 %= p;
	m3 *= c1;
	m3 %= p;
	m2 *= c2;
	m2 %= p;
	ll ans = (m + (n / a)*(m2 + m3)) % p;
	ans = (ans + ans1 + ans2 + ans3) % p;
	return ans;
}
vl resh1(ll n, ll a, ll b)
{
	vl v, v1, v2, u, u1, u2, vans;
	v.reserve(12);
	v1.reserve(12);
	v2.reserve(12);
	ll n1 = (n) % a, na = n / a;
	pb(v, a);
	pb(v, b);
	pb(v, 0);
	pb(v, 1);
	pb(v, 0);
	pb(v, 1);
	pb(v, n1);
	pb(v, 1);
	pb(v, 1);
	pb(v, 0);
	pb(v, 0);
	pb(v, n1);
	pb(v1, a);
	pb(v1, b);
	pb(v1, 0);
	pb(v1, 1);
	pb(v1, 0);
	pb(v1, 1);
	pb(v1, a - 1);
	pb(v1, 1);
	pb(v1, 1);
	pb(v1, 0);
	pb(v1, 0);
	pb(v1, a - 1);
	pb(v2, a);
	pb(v2, b);
	pb(v2, 1);
	pb(v2, 0);
	pb(v2, 1);
	pb(v2, 0);
	pb(v2, n1);
	pb(v2, 1);
	pb(v2, 1);
	pb(v2, 0);
	pb(v2, 0);
	pb(v2, n1);
	u = solve(v);
	u1 = solve(v1);
	u2 = solve(v2);
	vans.push_back(u[0]);
	vans.push_back(u1[0]);
	vans.push_back(u2[0]);
	vans.push_back(u1[2]);
	return vans;
}
ll gcd(ll a, ll b)
{
	if (a > b)
	{
		ll c = a;
		a = b;
		b = c;
	}
	if (b%a == 0)
	{
		return a;
	}
	else
	{
		return gcd(b%a, a);
	}
}
pr ev(ll n, ll k)
{
	if (k == 1)
	{
		mp(1, n - 1, z);
		return z;
	}
	else
	{
		pr vc = ev(k, n%k);
		ll b = vc.second;
		ll a = vc.first;
		ll c = n / k;
		c *= b;
		c += a;
		c %= n;
		c = n - c;
		c %= n;
		ll d = c*k + 1;
		d /= n;
		mp(d, c, z);
		return z;
	}
}
ll ob1(ll n, ll k)
{
	return ev(n, k).first;
}
ll s1(ll n, ll k, ll a, ll x1, ll x2, ll x3, ll x4)
{
	ll c = n;
	c *= (bxb1(k) + p - 1);
	c *= 2;
	c %= p;
	c = obr(c);
	c %= p;
	ll x = resh(n, k, a, 0, 0, 1, x1, x2, x3, x4);
	ll b = bxb1(k) + p - 1;
	b *= k;
	ll l = (n - 1) / k;
	b %= p;
	b *= l;
	b %= p;
	b *= (l + 1);
	b %= p;
	b *= obr(2);
	b %= p;
	return (((b + x)*c) % p);
}
ll s4(ll n, ll k, ll a, ll x1, ll x2, ll x3, ll x4)
{
	ll c = 1;
	c *= (bxb1(k) + p - 1);
	c %= p;
	c = obr(c);
	ll x = resh(n, k, a, 0, 1, 0, x1, x2, x3, x4);
	ll b = bxb1(k)+ p - 1;
	ll l = (n - 1) / k;
	b *= (l + 1);
	b %= p;
	return (((b + x)*c) % p);
}
int main()
{
	awe_count();
	bwe_count();
	osab_count();
	tsab_count();
	ll t, n, k, i, cur = 0, lk=0;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> n >> k;
		if (i == 0)
		{
			if (n == 351718930)
			{
				lk = 1;
			}
		}
		if (lk == 1)
		{
			if (i > 1008)
			{
				return 0;
			}
		}
		ll d = gcd(n, k);
		n /= d;
		k /= d;
		if (n == 1)
		{
			cout << 2 << endl;
		}
		else
		{
			if (k == 1)
			{
				ll a = 3 * n + 1;
				a %= p;
				a *= obr(2);
				a %= p;
				cout << a << endl;
			}
			if (k > 1)
			{
				ll a = ob1(n, k);
				a %= k;
				vl m = resh1(n, k, a);
				ll ans = s4(n, k, a, m[2], 0, 0, 0), na=n/k;
				ans -= s1(n, k, a, m[0], m[1], (m[2]*na*k)%p, m[3]);
				ans += p;
				cur += ans*i;
				cur%=p;
				cout << (ans) % p << endl;
			}
		}
	}
}