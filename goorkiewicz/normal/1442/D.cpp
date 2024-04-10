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


const int N = 3005;
const int M = (1 << 12);
int n, i, j, k;
ll out;
int wei [N];
ll val [N];
ll res [N];
vector <ll> vec [N];
vector <int> tree [M+M];
vector < pair <ll*, ll> > changes;

void insert (int a, int b, int v)
	{
	a += M;
	b += M;
	if (a > b) return;
	tree[a].pb(v);
	if (a == b) return;
	tree[b].pb(v);
	while (a/2 != b/2)
		{
		if (a%2 == 0) tree[a+1].pb(v);
		if (b%2 == 1) tree[b-1].pb(v);
		a /= 2;
		b /= 2;
		}
	}

void change (ll& a, ll b)
	{
	changes.pb({&a, a});
	a = b;
	}

void backup (int state)
	{
	while (changes.size() > state)
		{
		*changes.back().f = changes.back().s;
		changes.pop_back();
		}
	}

void update (int id)
	{
	int WEI = wei[id];
	ll VAL = val[id];
	
	for (i=k - WEI; i >= 0; i--)
		if (res[i+WEI] < res[i] + VAL)
			change(res[i+WEI], res[i] + VAL);
	}

void answer (int id)
	{
	for (i=0; i<=k; i++)
		{
		if (i > wei[id])
			continue;
		umax(out, vec[id][i] + res[k - i]);
		}
	}

void dfs (int u)
	{
	int state = changes.size();

	for (int a : tree[u])
		update(a);
	
	if (u >= M)
		{
		if (u - M >= 1 && u - M <= n)
			answer(u - M);
		backup(state);
		return;
		}

	dfs(u + u + 0);
	dfs(u + u + 1);

	backup(state);
	}

int main ()
	{
	scanf ("%d%d", &n, &k);

	for (i=1; i<=n; i++)
		{
		scanf ("%d", &wei[i]);
		
		vec[i].resize(wei[i] + 1);
		
		for (j=1; j<vec[i].size(); j++)
			{
			scanf ("%lld", &vec[i][j]);
			vec[i][j] += vec[i][j-1];
			}
		
		val[i] = vec[i].back();
		
		insert(1, i - 1, i);
		insert(i + 1, n, i);
		}
	
	dfs(1);
	
	printf ("%lld\n", out);
	
	return 0;
	}