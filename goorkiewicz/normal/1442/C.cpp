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
using piii=pair < pair <int,int> , int>;

const int inf = 1000000005;
const int mod = 998244353;
const int N = 200005;
int n, m, i, j;
vector <int> e [2][N];
unordered_map <int,int> dis [N];
pair <int,int> out;
priority_queue <piii, vector <piii>, greater <piii> > Q;
int vis [2][N];

int main ()
	{
	scanf ("%d%d", &n, &m);

	while (m--)
		{
		int a, b;
		scanf ("%d%d", &a, &b);
		e[0][a].pb(b);
		e[1][b].pb(a);
		}

	dis[0][1] = 0;
	Q.push({{0, 0}, 1});

	out = {inf, inf};

	for (i=0; i<=n; i++)
		vis[0][i] = vis[1][i] = inf;
	
	while (!Q.empty())
		{
		piii p = Q.top();
		Q.pop();
		int u = p.s;
		int d1 = p.f.f;
		int d2 = p.f.s;

		umin(vis[d1%2][u], d1);

		if (dis[d1][u] != d2)
			continue;

		if (u == n)
			{
			if (out.f <= 25 && d1 <= 25)
				{
				if ((1 << out.f) - 1 + out.s > (1 << d1) - 1 + d2 )
					out = {d1, d2};
				}
			else
				out = min(out, {d1, d2});
			}

		for (int v : e[d1%2][u])
			if (dis[d1].find(v) == dis[d1].end() || dis[d1][v] > dis[d1][u] + 1)
				{
				dis[d1][v] = dis[d1][u] + 1;
				Q.push({{d1, dis[d1][v]}, v});
				}

		if (d1 == 0)
			{
			dis[d1 + 1][u] = dis[d1][u];
			Q.push({{d1+1, dis[d1][u]}, u});
			}
		else
			{
			if (d1 <= 24)
				{
				dis[d1 + 1][u] = dis[d1][u];
				Q.push({{d1+1, dis[d1][u]}, u});
				}
			else if (vis[(d1 + 1)%2][u] == inf)
				{
				dis[d1 + 1][u] = dis[d1][u];
				Q.push({{d1+1, dis[d1][u]}, u});
				}
			}

		}

	int res = 1;
	while (out.f--)
		(res += res) %= mod;

	res -= 1;
	res += out.s;

	res %= mod;
	res += mod;
	res %= mod;

	printf ("%d\n", res);	
	
	return 0;
	}