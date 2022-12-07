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

const int N = 5005;
int n, m, i, j, n1, n2, n3;
bool vis [N];
bool col [N];
int fr [N];
bool dp [N];
int out [N];
vector <int> e [N];
vector <int> vec [2];
vector < pair < vector <int> , vector <int> > > nom;

void dfs (int u)
	{
	vis[u] = true;
	vec[col[u]].pb(u);
	for (int v : e[u])
		{
		if (vis[v] == false)
			{
			col[v] = !col[u];
			dfs(v);
			}
		if (col[v] == col[u])
			{
			printf ("NO\n");
			exit(0);
			}
		}
	}

int main ()
	{
	scanf ("%d%d", &n, &m);
	
	scanf ("%d%d%d", &n1, &n2, &n3);
	
	while (m--)
		{
		int a, b;
		scanf ("%d%d", &a, &b);
		e[a].pb(b);
		e[b].pb(a);
		}

	for (i=1; i<=n; i++)
		if (vis[i] == false)
			{
			vec[0].clear();
			vec[1].clear();
			dfs(i);
			if (ss(vec[0]) < ss(vec[1]))
				swap(vec[0], vec[1]);
			n2 -= min(ss(vec[0]), ss(vec[1]));
			nom.pb({vec[0], vec[1]});
			}

	//dbg(nom);
	//dbg(n2);

	dp[0] = true;
	for (j=0; j<ss(nom); j++)
		{
		int val = ss(nom[j].f) - ss(nom[j].s);
		//dbg(val);
		for (i=n2; i>=val; i--)
			if (dp[i-val] == true && dp[i] == false)
				{
				dp[i] = true;
				fr[i] = j;
				//printf ("dp[%d] = %d (%d)\n", i, true, fr[i]);
				}
		}

	if (dp[n2] == false)
		{
		printf ("NO\n");
		return 0;
		}

	vector <int> res (0);

	i = n2;
	while (i > 0)
		{
		j = fr[i];
		res.pb(j);
		int val = ss(nom[j].f) - ss(nom[j].s);
		i -= val;
		}
	
	for (auto p : nom)
		for (int u : p.s)
			out[u] = 2;
	
	for (int i : res)
		{
		for (int u : nom[i].s)
			out[u] = 0;
		for (int u : nom[i].f)
			out[u] = 2;
		}

	
	for (i=1; i<=n && n1 > 0; i++)
		if (out[i] == 0)
			{
			out[i] = 1;
			n1--;
			}

	for (i=1; i<=n; i++)
		if (out[i] == 0)
			{
			out[i] = 3;
			n3--;
			}
	
	assert(n1 == 0 && n3 == 0);

	printf ("YES\n");
	for (i=1; i<=n; i++)
		printf ("%d", out[i]);
	
	return 0;
	}