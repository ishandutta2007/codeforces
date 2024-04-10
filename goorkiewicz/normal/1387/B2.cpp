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


const int N = 1000005;
int n, i, j;
int S [N];
int D [N];
int out [N];
vector <int> e [N];
vector <int> vec;

void make_sizes (int u, int f)
	{
	S[u] = 1;
	for (int v : e[u])
		if (v != f)
			{
			make_sizes(v, u);
			S[u] += S[v];
			}
	}

void make_depths (int u, int f)
	{
	for (int v : e[u])
		if (v != f)
			{
			D[v] = D[u] + 1;
			make_depths(v, u);
			}
	}

int find_centro (int u, int f)
	{
	for (int v : e[u])
		if (v != f)
			if (S[v] * 2 > n)
				return find_centro(v, u);
	return u;
	}

void make_vec (int u, int f)
	{
	vec.pb(u);
	for (int v : e[u])
		if (v != f)
			make_vec(v, u);
	}

int main ()
	{
	scanf ("%d", &n);

	for (i=1; i<n; i++)
		{
		int a, b;
		scanf ("%d%d", &a, &b);
		e[a].pb(b);
		e[b].pb(a);
		}

	make_sizes(1, 1);
	int c = find_centro(1, 1);
	make_sizes(c, c);
	make_depths(c, c);

	for (int u : e[c])
		if (S[u] * 2 == n)
			make_vec(u, c);

	for (int u : e[c])
		if (S[u] * 2 != n)
			make_vec(u, c);
	
	vec.pb(c);
	
	int i = 0;
	vector <int> tab (n);
	for (int u : vec)
		{
		tab[i] = u;
		i += 2;
		if (i >= n)
			i = 1;
		}

	
	ll sum = 0;
	for (i=1; i<=n; i++)
		sum += D[i];

	printf ("%lld\n", sum * 2);

	for (i=0; i<n; i++)
		out[tab[i]] = tab[(i+1)%n];
	
//	dbg(vec);
//	dbg(tab);
	
	for (i=1; i<=n; i++)	
		printf ("%d ", out[i]);
	printf ("\n");

	return 0;
	}