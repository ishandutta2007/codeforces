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

const lf eps = 0.000000005;
const lf inf = 1000000000000000005.0;
const int N = 1000005;
int n, i, j;
vector < pair <lf, int> > M;
vector < pair <int, pair <int,int> > > vec;
vector < pair <lf, pair <int,int> > > elo;

lf proj (const lf& slo, cint& x, cint& y) {
	return x + y * slo;
	}

int main ()
	{
	scanf ("%d", &n);
	
	while (n--)
		{
		int ax, bx, y;
		scanf ("%d%d%d", &ax, &bx, &y);
		vec.pb({y, {ax, bx}});
		}

	sort(all(vec));

	for (i=0; i<ss(vec); i++)
		for (j=0; j<i; j++)
			{
			auto A = vec[i];
			auto B = vec[j];
			if (A.f == B.f) continue;
			lf L = lf(B.s.f - A.s.s) / lf(A.f - B.f);
			lf R = lf(B.s.s - A.s.f) / lf(A.f - B.f);
			L += eps;
			R -= eps;
			
			assert(L < R);
			
			M.pb({L, 1});
			M.pb({R, -1});
			
			lf S1 = lf(B.s.f - A.s.f) / lf(A.f - B.f);
			lf S2 = lf(B.s.s - A.s.s) / lf(A.f - B.f);

			elo.pb({S1, {i, j}});
			elo.pb({S2, {i, j}});
			}
	
	sort(all(M));

	sort(all(elo));
	reverse(all(elo));

	int bil = 0;
	
	lf L = inf;
	lf R = -inf;
	lf out = inf;

	int lx, ly;
	int rx, ry;

	lx = vec[0].s.f;
	ly = vec[0].f;
	rx = vec[0].s.f;
	ry = vec[0].f;

	for (i=0; i<ss(vec); i++)
		elo.pb({-inf, {i, i}});
	
	for (pair <lf, int> p : M)
		{
		bil += p.s;
		assert(bil >= 0);
		lf ang = p.f;
		if (bil == 0 || (bil == 1 && p.s == 1))
			{
			while (!elo.empty() && elo.back().f <= ang)
				{
				auto& A = elo.back();
				elo.pop_back();
				if (proj(ang, lx, ly) > proj(ang, vec[A.s.f].s.f, vec[A.s.f].f)) { lx = vec[A.s.f].s.f; ly = vec[A.s.f].f; }
				if (proj(ang, rx, ry) < proj(ang, vec[A.s.f].s.f, vec[A.s.f].f)) { rx = vec[A.s.f].s.f; ry = vec[A.s.f].f; }
				
				if (proj(ang, lx, ly) > proj(ang, vec[A.s.f].s.s, vec[A.s.f].f)) { lx = vec[A.s.f].s.s; ly = vec[A.s.f].f; }
				if (proj(ang, rx, ry) < proj(ang, vec[A.s.f].s.s, vec[A.s.f].f)) { rx = vec[A.s.f].s.s; ry = vec[A.s.f].f; }
				
				if (proj(ang, lx, ly) > proj(ang, vec[A.s.s].s.f, vec[A.s.s].f)) { lx = vec[A.s.s].s.f; ly = vec[A.s.s].f; }
				if (proj(ang, rx, ry) < proj(ang, vec[A.s.s].s.f, vec[A.s.s].f)) { rx = vec[A.s.s].s.f; ry = vec[A.s.s].f; }
				
				if (proj(ang, lx, ly) > proj(ang, vec[A.s.s].s.s, vec[A.s.s].f)) { lx = vec[A.s.s].s.s; ly = vec[A.s.s].f; }
				if (proj(ang, rx, ry) < proj(ang, vec[A.s.s].s.s, vec[A.s.s].f)) { rx = vec[A.s.s].s.s; ry = vec[A.s.s].f; }
				}
			
			umin(out, proj(ang, rx, ry) - proj(ang, lx, ly));
			}
		}

	if (M.empty())
		{
		lf L = inf;
		lf R = -inf;
		for (auto A : vec)
			{
			umin(L, A.s.f);
			umax(R, A.s.s);
			}
		printf ("%.13Lf\n", R - L);
		return 0;
		}
	
	printf ("%.13Lf\n", out);

	return 0;
	}