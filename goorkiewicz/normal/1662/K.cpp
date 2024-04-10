//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
namespace debug { template <class c> struct rge { c b, e; }; template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; } template <class c> char spk(...); template <class c> auto spk(c* a) -> decltype(cerr << *a, 0); struct stream { ~stream() { cerr << endl; } template <class c> typename enable_if <sizeof spk<c>(0) != 1, stream&>::type operator<<(c i) { cerr << boolalpha << i; return *this; } template <class c> typename enable_if <sizeof spk<c>(0) == 1, stream&>::type operator<<(c i) { return *this << range(begin(i), end(i)); } template <class a, class b> stream& operator<<(pair <a,b> p) { return *this << "(" << p.first << ", " << p.second << ")"; } template <class c> stream& operator<<(rge<c> d) { *this << "["; for (auto it=d.b; it!=d.e; it++) *this << ", " + 2 * (it == d.b) << *it; return *this << "]"; } stream& _dbg(const string& s, int i, int b) { return *this; } template <class c, class ... cs> stream& _dbg(const string& s, int i, int b, c arg, cs ... args) { if (i == (int)(s.size())) return (*this << ": " << arg); b += (s[i] == '(') + (s[i] == '[') + (s[i] == '{') - (s[i] == ')') - (s[i] == ']') - (s[i] == '}'); return (s[i] == ',' && b == 0) ? (*this << ": " << arg << "     ")._dbg(s, i + 1, b, args...) : (s[i] == ' ' ? *this : *this << s[i])._dbg(s, i + 1, b, arg, args...); } };}
#define dout debug::stream()
#define dbg(...) ((dout << ">> ")._dbg(#__VA_ARGS__, 0, 0, __VA_ARGS__))
#define f first
#define s second
#define sc scanf
#define pr printf
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define ss(x) ((int)((x).size()))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(b);i>=(a);i--)
#define upgrade cin.tie(0)->sync_with_stdio(0);
#define lowb(v,x) (lower_bound(all(v),(x))-v.begin())
#define uppb(v,x) (upper_bound(all(v),(x))-v.begin())
#define erase_duplicates(x) {sort(all(x));x.resize(unique(all(x))-x.begin());}
template <class p, class q> pair<p,q> operator-(pair<p,q> a, pair<p,q> b) { return mp(a.f - b.f, a.s - b.s); }
template <class p, class q> pair<p,q> operator+(pair<p,q> a, pair<p,q> b) { return mp(a.f + b.f, a.s + b.s); }
template <class p, class q> void umin(p &a, const q &b) { if (a > b) a = b; }
template <class p, class q> void umax(p &a, const q &b) { if (a < b) a = b; }
using ll=long long;
using cll=const ll;
using cint=const int;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
#define x first
#define y second

using lf = double;
using clf = const double;
using point = pair <lf,lf>;
using cpoint = const point;

lf AX = +1e9;
lf BX = -1e9;
lf AY = +1e9;
lf BY = -1e9;

point P[3];

static inline lf dis(cpoint& A, cpoint& B){
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

static inline lf check(cpoint& A, cpoint& B, cpoint& C, cpoint& D){
//	dbg(A, B, C, D, dis(A, D) + dis(B, D) + dis(C, D));
	return dis(A, D) + dis(B, D) + dis(C, D);
}

static inline lf search_x(cpoint& A, cpoint& B, cpoint& C, clf& x){
	lf a = AY;
	lf b = BY;
	int num = 40;
	while (num--){
		clf c1 = (a + a + b) / 3.0;
		clf c2 = (a + b + b) / 3.0;
		clf res1 = check(A, B, C, {x, c1});
		clf res2 = check(A, B, C, {x, c2});
		if (res1 < res2){
			b = c2;
		}else{
			a = c1;
		}
	}
	return check(A, B, C, {x, (a + b) / 2.0});
}

lf search(cpoint& A, cpoint& B, cpoint& C){
	lf a = AX;
	lf b = BX;
	int num = 40;
	while (num--){
		clf c1 = (a + a + b) / 3.0;
		clf c2 = (a + b + b) / 3.0;
		clf res1 = search_x(A, B, C, c1);
		clf res2 = search_x(A, B, C, c2);
		if (res1 < res2){
			b = c2;
		}else{
			a = c1;
		}
	}
	return search_x(A, B, C, (a + b) / 2.0);
}

lf check_xy(point p){
	lf res1 = search(p, P[0], P[1]);
	lf res2 = search(p, P[1], P[2]);
	lf res3 = search(p, P[2], P[0]);
	return max(res1, max(res2, res3));
}

lf check_x(lf x){
	lf a = AY;
	lf b = BY;
	int num = 40;
	while (num--){
		lf c1 = (a + a + b) / 3.0;
		lf c2 = (a + b + b) / 3.0;
		lf res1 = check_xy({x, c1});
		lf res2 = check_xy({x, c2});
		if (res1 < res2){
			b = c2;
		}else{
			a = c1;
		}
	}
	return check_xy({x, (a + b) / 2.0});
}

int main()
{
	rep(i, 0, 2){
		scanf("%lf%lf", &P[i].x, &P[i].y);
		umin(AX, P[i].x);
		umax(BX, P[i].x);
		umin(AY, P[i].y);
		umax(BY, P[i].y);
	}

	lf a = AX;
	lf b = BX;

	int num = 40;
	while (num--){
		lf c1 = (a + a + b) / 3.0;
		lf c2 = (a + b + b) / 3.0;
		lf res1 = check_x(c1);
		lf res2 = check_x(c2);
//		dbg(num, a, b, c1, c2, res1, res2);
		if (res1 < res2){
			b = c2;
		}else{
			a = c1;
		}
	}

	lf out = check_x((a + b) / 2.0);

	printf("%lf\n", out);

	return 0;
}