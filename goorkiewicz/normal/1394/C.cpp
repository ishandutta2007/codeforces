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
 

const int N = 1000005;
int n, i, j;
int x [N];
int y [N];
char str [N];
int XL, XR, YL, YR, DL, DR;
int X, Y;

bool check (int x, int y)
	{
	if (x == 0 && y == 0)
		return false;
	
	X = x;
	Y = y;
	
	if (x < XL) return false;
	if (x > XR) return false;
	
	if (y < YL) return false;
	if (y > YR) return false;
	
	if (y - x < DL) return false;
	if (y - x > DR) return false;
	
	return true;
	}

bool check (int r)
	{
	XL = 0;
	XR = N;
	
	YL = 0;
	YR = N;
	
	DL = -N;
	DR = N;
	
	for (i=1; i<=n; i++)
		{
		int xl = x[i] - r;
		int xr = x[i] + r;
		
		int yl = y[i] - r;
		int yr = y[i] + r;
		
		int dl = y[i] - x[i] - r;
		int dr = y[i] - x[i] + r;
		
//		dbg(x[i], y[i]);
//		dbg(xl, xr);
//		dbg(yl, yr);
//		dbg(dl, dr);
		
		umax(XL, xl);
		umin(XR, xr);
		
		umax(YL, yl);
		umin(YR, yr);
		
		umax(DL, dl);
		umin(DR, dr);
		}
	
//	dbg(XL, XR);
//	dbg(YL, YR);
//	dbg(DL, DR);
	
	if (XL > XR) return false;
	if (YL > YR) return false;
	if (DL > DR) return false;
	
	if (check(0, 1)) return true;
	if (check(1, 0)) return true;
	if (check(1, 1)) return true;
	
	if (check(XL, YL)) return true;
	if (check(XL, YR)) return true;
	if (check(XR, YL)) return true;
	if (check(XR, YR)) return true;
	
	if (check(XL, DL + XL)) return true;
	if (check(XL, DR + XL)) return true;
	if (check(XR, DL + XR)) return true;
	if (check(XR, DR + XR)) return true;
	
	if (check(YL - DL, YL)) return true;
	if (check(YL - DR, YL)) return true;
	if (check(YR - DL, YR)) return true;
	if (check(YR - DR, YR)) return true;
	
	return false;
	}

int main ()
	{
	scanf ("%d", &n);
	
	for (i=1; i<=n; i++)
		{
		scanf ("%s", str);
		int len = strlen(str);
		for (j=0; j<len; j++)
			{
			if (str[j] == 'B') x[i]++;
			if (str[j] == 'N') y[i]++;
			}
	//	dbg(i, x[i], y[i]);
		}
	
	int a = -1;
	int b = N;
	
	while (b - a > 1)
		(check((a+b)/2) ? b : a) = (a+b)/2;
	
	check(b);
	
	printf ("%d\n", b);
	
	vector <char> out;
	
	for (i=0; i<X; i++) out.pb('B');
	for (i=0; i<Y; i++) out.pb('N');
	
	for (char c : out)
		printf ("%c", c);
	printf ("\n");
	return 0;
	}