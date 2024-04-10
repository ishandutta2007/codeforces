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

const int N = 2005;
int my, mx, y, x, i;
ll out;
char t [N][N];
int r [N][N];
queue < pair <int,int> > Q;

bool inside (cint& y, cint& x)
	{
	if (y < 1 || y > my) return false;
	if (x < 1 || x > mx) return false;
	return true;
	}

bool check (int y, int x)
	{
	if (t[y][x] != t[y][x+1]) return true;
	if (t[y][x] != t[y][x-1]) return true;
	if (t[y][x] != t[y+1][x]) return true;
	if (t[y][x] != t[y-1][x]) return true;
	return false;
	}

void relax (cint& ay, cint& ax, cint& by, cint& bx)
	{
	if (inside(y, x) == false) return;
	if (r[ay][ax] != N) return;
	if (t[ay][ax] != t[by][bx]) return;
	r[ay][ax] = r[by][bx] + 1;
	Q.push({ay, ax});
	}

void solve ()
	{
	for (y=1; y<=my; y++)
		for (x=1; x<=mx; x++)
			r[y][x] = N;
	
	for (y=1; y<=my; y++)
		for (x=1; x<=mx; x++)
			if (check(y, x) == true)
				{
				r[y][x] = 1;
				Q.push({y, x});
				}

	while (!Q.empty())
		{
		y = Q.front().f;
		x = Q.front().s;
		Q.pop();
		relax(y, x+1, y, x);
		relax(y, x-1, y, x);
		relax(y+1, x, y, x);
		relax(y-1, x, y, x);
		}
	
//	for (y=1; y<=my; y++)
//		{
//		for (x=1; x<=mx; x++)
//			printf ("%d ", r[y][x]);
//		printf ("\n");
//		}

	for (y=1; y<=my; y++)
		for (x=1; x<=mx; x++)
			out += r[y][x];
	}

int main ()
	{
	scanf ("%d%d", &my, &mx);
	for (y=1; y<=my; y++)
		scanf ("%s", t[y] + 1);

	solve();
	

	printf ("%lld\n", out);
	return 0;
	}