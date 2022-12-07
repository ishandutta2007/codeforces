#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
stream& _dbg(const string& s, int i, int b) {} template <class c, class ... cs> stream& _dbg(const string& s, int i, int b, c arg, cs ... args) {
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
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

const int mod = 998244353;

struct node
	{
	int l = 0;
	int r = 0;
	ll out = 0;
	ll noL = 0;
	ll noR = 0;
	ll noLR = 0;
	bool elo = 0;
	};

ll ways (cint& a)
	{
	assert(a >= 0 && a <= 9);
	return a+1;
	}

ll ways (int a, cint& b)
	{
	if (a == 0) return 0;
	a = a * 10 + b;
	if (a > 18) return 0;
	return a - (a - 10) * 2 - 1;
	}

node merge (const node& a, const node& b)
	{
	if (a.elo == false && b.elo == false) return node();
	if (a.elo == false) return b;
	if (b.elo == false) return a;
	
	node c;
	
	c.elo = true;
	c.l = a.l;
	c.r = b.r;
	
	c.out = 0;
	c.out += a.out * b.out % mod;
	c.out += a.noR * b.noL % mod * ways(a.r, b.l) % mod;
	c.out %= mod;

	c.noL = 0;
	c.noL += a.noL * b.out % mod;
	c.noL += a.noLR * b.noL % mod * ways(a.r, b.l) % mod;
	c.noL %= mod;
	
	c.noR = 0;
	c.noR += a.out * b.noR % mod;
	c.noR += a.noR * b.noLR % mod * ways(a.r, b.l) % mod;
	c.noR %= mod;
	
	c.noLR = 0;
	c.noLR += a.noL * b.noR % mod;
	c.noLR += a.noLR * b.noLR % mod * ways(a.r, b.l) % mod;
	c.noLR %= mod;
	
	return c;
	}

const int N = 500005;
const int M = (1<<19);
char t [N];
int n, q, i;
node tree [M+M];

int main ()
	{
	scanf ("%d%d", &n, &q);
	scanf ("%s", t+1);

	for (i=1; i<=n; i++)
		{
		t[i] -= '0';
		node& a = tree[i+M];
		a.l = a.r = t[i];
		a.out = ways(a.l);
		a.noL = 1;
		a.noR = 1;
		a.noLR = 0;
		a.elo = true;
		}

	for (i=M-1; i>=1; i--)
		tree[i] = merge(tree[i+i+0], tree[i+i+1]);

	while (q--)
		{
		int u, v;
		scanf ("%d%d", &u, &v);
		t[u] = v;
		node& a = tree[u+M];
		a.l = a.r = t[u];
		a.out = ways(a.l);
		a.noL = 1;
		a.noR = 1;
		a.noLR = 0;
		a.elo = true;
		
		u += M;
		for (u/=2; u>=1; u/=2)
			tree[u] = merge(tree[u+u+0], tree[u+u+1]);

		printf ("%lld\n", tree[1].out);
		}

	
	return 0;
	}