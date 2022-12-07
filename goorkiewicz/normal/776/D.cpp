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

struct twosat
	{
	int n;
	vector < vector <int> > e;
	vector < vector <int> > g;
	
	twosat (int s) : n(s+s), e(s+s), g(s+s) { }
	
	void add (bool neg1, int arg1, bool neg2, int arg2)
		{
		int u = arg1*2 + neg1;
		int v = arg2*2 + neg2;
		e[u^1].pb(v);
		e[v^1].pb(u);
		g[v].pb(u^1);
		g[u].pb(v^1);
		}
	
	vector <bool> solve () // empty <=> no solution
		{
		int i;
		vector <int> ord;
		vector <int> scc (n, 0);
		vector <bool> vis (n, 0);
		vector < vector <int> > S;
		
		function <void(int)> dfs1 = [&] (int u)
			{
			vis[u] = true;
			for (int v : e[u])
				if (vis[v] == false)
					dfs1(v);
			ord.pb(u);
			};
		
		function <void(int)> dfs2 = [&] (int u)
			{
			scc[u] = ss(S) - 1;
			S.back().pb(u);
			vis[u] = true;
			for (int v : g[u])
				if (vis[v] == false)
					dfs2(v);
			};
		
		for (i=0; i<n; i++)
			if (vis[i] == false)
				dfs1(i);
		
		fill(all(vis), false);
		reverse(all(ord));
		
		for (int u : ord)
			if (vis[u] == false)
				{
				S.pb(vector <int> (0));
				dfs2(u);
				}
		
		for (i=0; i<n; i++)
			if (scc[i] == scc[i^1])
				return vector <bool> (0);
		
		//return vector <bool> (1);
		
		vector < vector <int> > E (ss(S));
		
		for (int u=0; u<n; u++)
			for (int v : e[u])
				if (scc[u] != scc[v])
					E[scc[u]].pb(scc[v]);
		
		for (vector <int>& vec : E)
			erase_duplicates(vec);
		
		vector <int> deg (ss(S), 0);
		queue <int> Q;
		
		for (i=0; i<ss(S); i++)
			for (int v : E[i])
				deg[v]++;
		
		for (i=0; i<ss(S); i++)
			if (deg[i] == 0)
				Q.push(i);
		
		vector <int> topsort;
		
		while (!Q.empty())
			{
			int u = Q.front();
			Q.pop();
			topsort.pb(u);
			for (int v : E[u])
				if (--deg[v] == 0)
					Q.push(v);
			}
		
		reverse(all(topsort));
		
		vector <bool> done (ss(S));
		vector <bool> out (ss(S));
		
//		dbg(n);
//		dbg(e);
//		dbg(S);
//		dbg(E);
		
		for (int s : topsort)
			if (done[s] == false)
				{
				out[s] = true;
				done[s] = true;
				for (int u : S[s])
					{
					done[scc[u^1]] = true;
					out[scc[u^1]] = false;
					}
				}
		
		vector <bool> res (n/2);
		
		for (i=0; i<n; i+=2)
			{
			assert(out[scc[i]] != out[scc[i+1]]);
			res[i/2] = out[scc[i]];
			}
		
		return res;
		}
	};

const int N = 100005;
int n, m, i, j;
int t [N];
vector <int> v [N];

int main ()
	{
	scanf ("%d%d", &n, &m);
	
	for (i=0; i<n; i++)
		scanf ("%d", &t[i]);
	
	for (i=0; i<m; i++)
		{
		scanf ("%d", &j);
		while (j--)
			{
			int a;
			scanf ("%d", &a);
			v[a-1].pb(i);
			}
		}
	
	twosat G (m);
	
	for (i=0; i<n; i++)
		{
		assert(ss(v[i]) == 2);
		int a = v[i][0];
		int b = v[i][1];
		G.add(t[i], a, false, b);
		G.add(!t[i], a, true, b);
		}
	
	printf ("%s\n", G.solve().empty() ? "NO" : "YES");
	
	return 0;
	}