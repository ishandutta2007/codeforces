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

const int N = 1005;
int n, i, j, y, x, my, mx;

char t [N][N];
bool vis [N][N];
int dy [] = { 0, 1, 0,-1};
int dx [] = {-1, 0, 1, 0};

bool inside (int y, int x)
	{
	if (y > my || y < 1) return false;
	if (x > my || x < 1) return false;
	return true;
	}

void dfs (int y, int x)
	{
	vis[y][x] = true;
	for (int i=0; i<4; i++)
		{
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (t[yy][xx] == '#' && vis[yy][xx] == false)
			dfs(yy, xx);
		}
	}

int main ()
	{
	scanf ("%d%d", &my, &mx);
	for (y=1; y<=my; y++)
		scanf ("%s", t[y] + 1);

	for (y=1; y<=my; y++)
		{
		int elo = 0;
		for (x=1; x<=mx; x++)
			{
			if (t[y][x] == '#' && elo == 0)
				elo = 1;
			if (t[y][x] == '.' && elo == 1)
				elo = 2;
			if (t[y][x] == '#' && elo == 2)
				return printf ("-1\n"), 0;
			}
		}

	for (x=1; x<=mx; x++)
		{
		int elo = 0;
		for (y=1; y<=my; y++)
			{
			if (t[y][x] == '#' && elo == 0)
				elo = 1;
			if (t[y][x] == '.' && elo == 1)
				elo = 2;
			if (t[y][x] == '#' && elo == 2)
				return printf ("-1\n"), 0;
			}
		}

	int cnt1 = 0;
	int cnt2 = 0;

	for (y=1; y<=my; y++)
		{
		for (x=1; x<=mx; x++)
			if (t[y][x] == '#')
				break;
		if (x > mx)
			cnt1++;
		}
	
	for (x=1; x<=mx; x++)
		{
		for (y=1; y<=my; y++)
			if (t[y][x] == '#')
				break;
		if (y > my)
			cnt2++;
		}

	if (cnt1 == 0 && cnt2 > 0)
		return printf ("-1\n"), 0;
	if (cnt1 > 0 && cnt2 == 0)
		return printf ("-1\n"), 0;

	int out = 0;
	for (y=1; y<=my; y++)
		for (x=1; x<=mx; x++)
			if (t[y][x] == '#' && vis[y][x] == false)
				{
				out++;
				dfs(y, x);
				}
	
	printf ("%d\n", out);
	
	return 0;
	}