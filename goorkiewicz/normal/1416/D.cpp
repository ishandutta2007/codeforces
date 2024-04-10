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

const int N = 1000005;
int n, m, q, i, j;
int val [N];
int a [N];
int b [N];
int type [N];
int query [N];
int death [N];
bool imp [N];
int p [N];
int root [N];
bool del [N];
set < pair <int,int> > V [N];
vector < pair <int,int> > e [N];

inline int find (int a)
	{
	if (p[a] == a)
		return a;
	p[a] = find(p[a]);
	return p[a];
	}

inline void unite (int a, int b)
	{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	p[b] = a;
	}

void color (cint& u, cint& f, cint& r)
	{
	if (root[u] != 0)
		V[root[u]].erase({val[u], u});

	root[u] = r;
	V[root[u]].insert({val[u], u});
	
	for (const pair <int,int>& v : e[u])
		if (v.f != f && del[v.s] == false)
			color(v.f, u, r);
	}

queue < pair <int,int> > Q1, Q2;

int main ()
	{
	scanf ("%d%d%d", &n, &m, &q);

	for (i=1; i<=n; i++)
		scanf ("%d", &val[i]);

	for (i=1; i<=n; i++)
		p[i] = i;

	for (i=1; i<=m; i++)
		scanf ("%d%d", &a[i], &b[i]);
	
	for (i=1; i<=m; i++)
		death[i] = N;
	
	for (i=1; i<=q; i++)
		{
		scanf ("%d%d", &type[i], &query[i]);
		if (type[i] == 2)
			death[query[i]] = i;
		}
	
	vector <int> ord;
	for (i=1; i<=m; i++)
		ord.pb(i);

	sort(all(ord), [] (int x, int y) { return death[x] > death[y]; });
	
	for (int id : ord)
		if (find(a[id]) != find(b[id]))
			{
			unite(a[id], b[id]);
			imp[id] = true;
			}
	
	for (i=1; i<=m; i++)
		if (imp[i] == true)
			{
			e[a[i]].pb({b[i], i});
			e[b[i]].pb({a[i], i});
			}
	
	for (i=1; i<=n; i++)
		if (root[i] == 0)
			color(i, i, i);
	
	int now = n + 1;
	
	for (i=1; i<=q; i++)
		{
		if (type[i] == 1)
			{
			int r = root[query[i]];
			pair <int,int> p = *prev(V[r].end());
			printf ("%d\n", p.f);
			V[r].erase(p);
			val[p.s] = 0;
			p.f = 0;
			V[r].insert(p);
			}

		if (type[i] == 2)
			{
			int id = query[i];
			
			if (imp[id] == false)
				continue;
			
			assert(root[a[id]] == root[b[id]]);
			
			del[id] = true;
			
			while (!Q1.empty()) Q1.pop();
			while (!Q2.empty()) Q2.pop();
			
			Q1.push({a[id], b[id]});
			Q2.push({b[id], a[id]});
			
			while (true)
				{
				if (Q1.empty() || Q2.empty())
					break;
				
				int u, f;
				
				u = Q1.front().f;
				f = Q1.front().s;
				Q1.pop();
				for (const pair <int,int>& v : e[u])
					if (v.f != f && del[v.s] == false)
						Q1.push({v.f, u});
				
				u = Q2.front().f;
				f = Q2.front().s;
				Q2.pop();
				for (const pair <int,int>& v : e[u])
					if (v.f != f && del[v.s] == false)
						Q2.push({v.f, u});
				}
			
			if (Q1.empty())
				color(a[id], a[id], now++);
			else
				color(b[id], b[id], now++);
			}
		}

	return 0;
	}