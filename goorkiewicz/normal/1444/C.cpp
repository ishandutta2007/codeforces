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
int n, m, k, i, j;
int S [N];
int col [N];
int bad [N];
int BAD [N];
int par1 [N];
int par2 [N];
vector < pair <int*, int> > changes;
map < pair <int,int> , vector < pair <int,int> > > M;

void change (int& a, int b)
	{
	changes.pb({&a, a});
	a = b;
	}

int find (int a)
	{
	if (par1[a] == a)
		return a;
	return find(par1[a]);
	}

void unite1 (int a, int b)
	{
	a = find(a);
	b = find(b);
	
	int aa = par2[a] == 0 ? 0 : find(par2[a]);
	int bb = par2[b] == 0 ? 0 : find(par2[b]);
	
	if (a == b)
		{
		if (aa != 0 && aa == b)
			{
			change(bad[a], 1);
			change(bad[b], 1);
			change(bad[aa], 1);
			change(bad[bb], 1);
			change(BAD[col[a]], 1);
			change(BAD[col[b]], 1);
			change(BAD[col[aa]], 1);
			change(BAD[col[bb]], 1);
			}
		return;
		}
	
	if (S[a] < S[b])
		swap(a, b);

	change(par1[b], a);
	change(S[a], S[a] + S[b]);
	if (aa != 0)
		change(S[aa], S[a]);
	
	change(S[b], 0);
	if (bb != 0)
		change(S[bb], 0);
	
	if (bad[b] == 1)
		{
		change(bad[a], 1);
		change(BAD[col[a]], 1);
		if (aa != 0)
			{
			change(bad[aa], 1);
			change(BAD[col[aa]], 1);
			}
		}
	}

void unite2 (int a, int b)
	{
	a = find(a);
	b = find(b);
	
	int aa = par2[a] == 0 ? 0 : find(par2[a]);
	int bb = par2[b] == 0 ? 0 : find(par2[b]);

	if (a == b || bad[b] == 1)
		{
		change(bad[a], 1);
		change(bad[aa], 1);
		change(BAD[col[a]], 1);
		change(BAD[col[aa]], 1);
		return;
		}
	
	if (par2[b] != 0)
		unite1(a, par2[b]);
	else
		change(par2[b], a);

	if (par2[a] != 0)
		unite1(par2[a], b);
	else
		change(par2[a], b);
	}

void backup ()
	{
	while (changes.empty() == false)
		{
		(*changes.back().f) = changes.back().s;
		changes.pop_back();
		}
	}

int main ()
	{
	scanf ("%d%d%d", &n, &m, &k);
	
	for (i=1; i<=n; i++)
		scanf ("%d", &col[i]);

	for (i=1; i<=m; i++)
		{
		int a, b;
		scanf ("%d%d", &a, &b);
		if (col[a] > col[b])
			swap(a, b);
		M[{col[a], col[b]}].pb({a, b});
		}

	for (i=1; i<=n; i++)
		{
		par1[i] = i;
		par2[i] = 0;
		S[i] = 1;
		}
	
	for (auto E : M)
		if (E.f.f == E.f.s)
			for (pair <int,int> e : E.s)
				unite2(e.f, e.s);

	ll out = 0;
	
	changes.clear();
	
	for (auto E : M)
		if (E.f.f != E.f.s)
			{
			if (BAD[E.f.f] == true || BAD[E.f.s] == true)
				continue;
			
			for (pair <int,int> e : E.s)
				unite2(e.f, e.s);

			if (BAD[E.f.f] == true || BAD[E.f.s] == true)
				out++;
			
			backup();
			}
	
	ll good = 0;
	for (i=1; i<=k; i++)
		if (BAD[i] == false)
			good += 1;
	
	ll all = 1ll * good * (good - 1) / 2;
	
	printf ("%lld\n", all - out);
	return 0;
	}