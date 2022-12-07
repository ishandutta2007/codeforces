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
#define erase_duplicates(x) sort(all(x));(x).resize(distance((x).begin(), unique(all(x))));
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
 
const int N = (1<<20) + 5;
int n, m, i, j;
int a [N];
int b [N];
int cur [N];
bool vis [N];
vector <int> e [N];
vector <int> vec, out, res;

void dfs (int u)
	{
	while (cur[u] < ss(e[u]))
		{
		int r = e[u][cur[u]];
		cur[u]++;
		if (vis[r] == true)
			continue;
		vis[r] = true;
		vec.pb(r);
		int v = (a[r] == u ? b[r] : a[r]);
		dfs(v);
		}
	out.pb(vec.back());
	vec.pop_back();
	}

void solve (int k)
	{
	n = (1<<k);
	
	for (i=0; i<n; i++)
		{
		cur[i] = 0;
		e[i].clear();
		}
	
	for (i=1; i<=m; i++)
		{
		vis[i] = false;
		a[i] %= n;
		b[i] %= n;
		e[a[i]].pb(i);
		e[b[i]].pb(i);
		}
	
	for (i=0; i<n; i++)
		if (ss(e[i])%2 == 1)
			return;
	
	vec.clear();
	out.clear();
	res.clear();
	
	vec.pb(0);
	
	for (i=0; i<n; i++)
		if (ss(e[i]) > 0)
			{
			dfs(i);
			break;
			}
	
	out.pop_back();
	reverse(all(out));
	
	if (ss(out) != m)
		return;
	
	int u = i;
	
	for (int r : out)
		{
		if (a[r] == u)
			{
			res.pb(r+r-1);
			res.pb(r+r);
			u = b[r];
			}
		else
			{
			res.pb(r+r);
			res.pb(r+r-1);
			u = a[r];
			}
		}
	
	if (u != i)
		return;
	
	printf ("%d\n", k);
	for (int a : res)
		printf ("%d ", a);
	
	printf ("\n");
	exit(0);
	}

int main ()
	{
	scanf ("%d", &m);
	
	for (i=1; i<=m; i++)
		scanf ("%d%d", &a[i], &b[i]);
	
	for (j=20; j>=0; j--)
		solve(j);
	
	assert(false);
	return 0;
	}