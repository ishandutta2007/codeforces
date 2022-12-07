//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
// DEBUG
namespace debug {
template <class c> struct rge { c b, e; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> char elo(...);
template <class c> auto elo(c* a) -> decltype(cerr << *a, 0);
struct stream {
~stream() { cerr << endl; }
template <class c> typename enable_if <sizeof elo<c>(0) != 1, stream&>::type operator<<(c i) {
	cerr << boolalpha << i; return *this; }
template <class c> typename enable_if <sizeof elo<c>(0) == 1, stream&>::type operator<<(c i) {
	return *this << range(begin(i), end(i)); }
template <class a, class b> stream& operator<<(pair <a,b> p) {
	return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> stream& operator<<(rge<c> d) {
	*this << "[";
	for (auto it=d.b; it!=d.e; it++)
		*this << ", " + 2 * (it == d.b) << *it;
	return *this << "]"; }
stream& _dbg(const string& s, int i, int b) {}
template <class c, class ... cs>
stream& _dbg(const string& s, int i, int b, c arg, cs ... args) {
	if (i == s.size()) return (*this << ": " << arg << "");
	b += (s[i] == '(') + (s[i] == '[') + (s[i] == '{');
	b -= (s[i] == ')') + (s[i] == ']') + (s[i] == '}');
	if (s[i] == ',' && b == 0) return (*this << ": " << arg << "     ")._dbg(s, i+1, b, args...);
	return (s[i] == ' ' ? *this : *this << s[i])._dbg(s, i+1, b, arg, args...); }
};}
#define dout debug::stream()
#define dbg(...) ((dout << ">> ")._dbg(#__VA_ARGS__, 0, 0, __VA_ARGS__))

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

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
using vl=vector<ll>;
using vi=vector<int>;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using vll=vector<pair<ll,ll>>;
using vii=vector<pair<int,int>>;


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

const int N = 1000005;
int n, m, i, j;
int deg [N];
int dp1 [N]; // - najmniejszy, ktory do mnie prowadzi
int dp2 [N]; // - najmniejszy, do ktorego ja prowadze
int pos [N];
vector <int> e [N];
vector <int> g [N];
queue <int> Q;
vector <int> vec;
string out;

int main ()
	{
	scanf ("%d%d", &n, &m);

	while (m--)
		{
		int a, b;
		scanf ("%d%d", &a, &b);
		e[a].pb(b);
		g[b].pb(a);
		deg[b]++;
		}

	for (i=1; i<=n; i++)
		if (deg[i] == 0)
			Q.push(i);
	
	while (!Q.empty())
		{
		i = Q.front();
		Q.pop();
		vec.pb(i);
		for (int v : e[i])
			if (--deg[v] == 0)
				Q.push(v);
		}

	if (ss(vec) != n)
		return printf ("-1\n"), 0;
	
	for (i=0; i<n; i++)
		{
		dp1[i] = vec[i];
		dp2[i] = vec[i];
		pos[vec[i]] = i;
		}

	for (i=0; i<n; i++)
		{
		int u = vec[i];
		for (int v : g[u])
			{
			j = pos[v];
			assert(j < i);
			umin(dp1[i], dp1[j]);
			}
		}

	for (i=n-1; i>=0; i--)
		{
		int u = vec[i];
		for (int v : e[u])
			{
			j = pos[v];
			assert(j > i);
			umin(dp2[i], dp2[j]);
			}
		}

	int cnt = 0;
	for (i=1; i<=n; i++)
		{
		if (dp1[pos[i]] >= i && dp2[pos[i]] >= i)
			{
			cnt++;
			out += "A";
			}
		else
			{
			out += "E";
			}
		}

	printf ("%d\n%s\n", cnt, out.c_str());
	return 0;
	}