//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
namespace debug {
template <class c> struct rge { c b, e; }; template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> char elo(...); template <class c> auto elo(c* a) -> decltype(cerr << *a, 0);
struct stream { ~stream() { cerr << endl; }
template <class c> typename enable_if <sizeof elo<c>(0) != 1, stream&>::type operator<<(c i) { cerr << boolalpha << i; return *this; }
template <class c> typename enable_if <sizeof elo<c>(0) == 1, stream&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
template <class a, class b> stream& operator<<(pair <a,b> p) { return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> stream& operator<<(rge<c> d) { *this << "["; for (auto it=d.b; it!=d.e; it++) *this << ", " + 2 * (it == d.b) << *it; return *this << "]"; }
stream& _dbg(const string& s, int i, int b) { return *this; } template <class c, class ... cs> stream& _dbg(const string& s, int i, int b, c arg, cs ... args) {
if (i == s.size()) return (*this << ": " << arg << ""); b += (s[i] == '(') + (s[i] == '[') + (s[i] == '{'); b -= (s[i] == ')') + (s[i] == ']') + (s[i] == '}');
if (s[i] == ',' && b == 0) return (*this << ": " << arg << "     ")._dbg(s, i+1, b, args...); return (s[i] == ' ' ? *this : *this << s[i])._dbg(s, i+1, b, arg, args...); } };}
#define dout debug::stream()
#define dbg(...) ((dout << ">> ")._dbg(#__VA_ARGS__, 0, 0, __VA_ARGS__))
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
#define f first
#define s second
#define sc scanf
#define pr printf
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define ss(x) ((int)((x).size()))
#define rep(i, a, b) for(int (i)=(a);i<=(b);(i)++)
#define per(i, a, b) for(int (i)=(b);i>=(a);(i)--)
#define lowb(v, x) (lower_bound(all(v),(x))-(v).begin())
#define uppb(v, x) (upper_bound(all(v),(x))-(v).begin())
#define upgrade ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define erase_duplicates(x) {sort(all(x));(x).resize(distance((x).begin(), unique(all(x))));}
template <class p, class q> pair<p,q> operator-(pair<p,q> a, pair<p,q> b) { return mp(a.f-b.f, a.s-b.s); }
template <class p, class q> pair<p,q> operator+(pair<p,q> a, pair<p,q> b) { return mp(a.f+b.f, a.s+b.s); }
template <class p, class q> void umin(p& a, const q& b) { if (a > b) a = b; }
template <class p, class q> void umax(p& a, const q& b) { if (a < b) a = b; }
using lf=long double;
using ll=long long;
using cll=const ll;
using cint=const int;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using big=__int128_t;
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

const int N = 1000005;
ll my, mx;
int n, i, j;
ll t [N];

ll pw (ll a, ll b, ll mod)
	{
	ll res = 1;
	while (b > 0)
		{
		if (b%2 == 1)
			res = (big(res) * big(a)) % mod;
		a = (big(a) * big(a)) % mod;
		b /= 2;
		}
	return res;
	}	

int main ()
	{
	scanf ("%lld%lld%d", &my, &mx, &n);
	
	ll nww = 1;
	for (i=0; i<n; i++)
		{
		scanf ("%lld", &t[i]);
		
		nww /= __gcd(nww, t[i]);

		if (big(nww) * big(t[i]) > big(my))
			return !printf ("NO\n");

		nww *= t[i];
		}

	ll y = nww;
	assert(y <= my);
	
	vector < pair <ll,ll> > fac;

	for (ll d=2; d*d <= nww; d++)
		if (nww%d == 0)
			{
			fac.pb({1, d});
			while (nww%d == 0)
				{
				fac.back().f *= d;
				nww /= d;
				}
			}

	if (nww > 1)
		fac.pb({nww, nww});

	ll x = 1;
	nww = 1;

	for (auto [d, p] : fac)
		{
		ll r = 0;
		while (r < n && t[r]%d != 0)
			r++;
		
		dbg(d, r, x);
		assert(r < n);
		assert(t[r]%d == 0);
		
		r = d - r;
		r %= d;

		ll a = (((r - x) % d) + d) % d;
		ll b = nww % d;
		assert(__gcd(nww, d) == 1);
		ll c = pw(b, d - (d / p) - 1, d);

		if (big(c) * big(b) % big(d) != big(1))
			return !printf ("c=%lld b=%lld d=%lld p=%lld\n", c, b, d, p);
		
		c = (ll)((big(c) * big(a)) % big(nww * d));
		c = (ll)((big(c) * big(nww)) % big(nww * d));

		x += c;
		x %= (nww * d);
	
		if (x + n - 1 > mx)
			return !printf ("NO\n");
		
		nww *= d;
		}
	
	assert(nww == y);
	
	if (x == 0)
		x = nww;
	
	if (x + n - 1 > mx)
		return !printf ("NO\n");
	
	dbg(y, x);

	for (i=0; i<n; i++)
		if (__gcd(y, x + i) != t[i])
			return !printf ("NO\n");
	
	printf ("YES\n");
	
	return 0;
	}