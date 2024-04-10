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
int n, m, i, j;
int p [N];
int bil [N];
bool dep [N];
bool vis [N];
vector < pair <int,int> > e [N];
vector < pair <int,int> > g [N];
vector <int> nodes;

int find (int a)
	{
	if (p[a] == a)
		return a;
	return p[a] = find(p[a]);
	}

bool unite (int a, int b)
	{
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	p[a] = b;
	return true;
	}

void dfs (int u)
	{
	nodes.pb(u);
	vis[u] = true;
	for (pair <int,int> v : e[u])
		if (vis[v.f] == false)
			{
			bil[v.f] = v.s - bil[u];
			dep[v.f] = !dep[u];
//			dbg(u, v, bil[v.f]);
			dfs(v.f);
			}
	}


void solve (int root)
	{
	nodes.clear();

	dfs(root);
	
	bool defined = false;
	int out;
	
//	for (i=1; i<=n; i++)
//		dbg(i, bil[i]);

	for (int a : nodes)
		for (pair <int,int> p : g[a])
			{
			int b = p.f;
			int c = p.s;
			
			if (dep[a] == dep[b])
				{
				int x = (c - bil[a] - bil[b]);
				if (dep[a] == 1) x = -x;
				x /= 2;
				if (defined == true && out != x)
					{
					printf ("NO\n");
					exit(0);
					}
				defined = true;
				out = x;
				}

			if (dep[a] != dep[b])
				if (bil[a] + bil[b] != c)
					{
					printf ("NO\n");
					exit(0);
					}
			}
	
	if (defined == true)
		{
		for (int u : nodes)
			{
			if (dep[u] == 0) bil[u] += out;
			if (dep[u] == 1) bil[u] -= out;
			}
		return;
		}

	vector <int> vec;

	for (int u : nodes)
		{
		if (dep[u] == 0) vec.pb(-bil[u]);
		if (dep[u] == 1) vec.pb(bil[u]);
		}

	sort(all(vec));

	//dbg(vec);

	out = vec[(ss(vec)-1)/2];
	
	for (int u : nodes)
		{
		if (dep[u] == 0) bil[u] += out;
		if (dep[u] == 1) bil[u] -= out;
		}
	}

int main ()
	{
	scanf ("%d%d", &n, &m);
	
	for (i=1; i<=n; i++)
		p[i] = i;
	
	while (m--)
		{
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c);
		c *= 2;
		if (unite(a, b) == true)
			{
			e[a].pb({b, c});
			e[b].pb({a, c});
			}
		else
			{
			g[a].pb({b, c});
			g[b].pb({a, c});
			}
		}

	for (i=1; i<=n; i++)
		if (vis[i] == false)
			solve(i);

	printf ("YES\n");

	for (i=1; i<=n; i++)
		printf ("%Lf ", lf(bil[i]) / lf(2));
	printf ("\n");

	return 0;
	}