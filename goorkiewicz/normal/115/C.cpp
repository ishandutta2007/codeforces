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
using lf=long double;
using ll=long long;
using cll=const ll;
using cint=const int;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

const int mod = 1000003;
const int N = 500005;
bool px[N][2];
bool py[N][2];

int main()
{
	upgrade;
	
	int my, mx;
	
	cin >> my >> mx;

	vector <string> t(my);

	for (string& s : t){
		cin >> s;
	}

	rep(y, 0, my - 1){
		rep(x, 0, mx - 1){
			if (t[y][x] == '.') continue;
			int v = t[y][x] - '1';
			int vy = v / 2;
			int vx = vy ^ (v % 2);
			py[y][(x % 2) ^ vy] = true;
			px[x][(y % 2) ^ vx] = true;
		}
	}
	
	int out = 1;
	
	rep(y, 0, my - 1){
		if (py[y][0] == 1 && py[y][1] == 1) out = 0;
		if (py[y][0] == 0 && py[y][1] == 0) (out *= 2) %= mod;
	}
	
	rep(x, 0, mx - 1){
		if (px[x][0] == 1 && px[x][1] == 1) out = 0;
		if (px[x][0] == 0 && px[x][1] == 0) (out *= 2) %= mod;
	}

	cout << out << '\n';
	
	return 0;
}