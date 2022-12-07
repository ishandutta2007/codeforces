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
stream& _dbg(const string& s, int i, int b) { return *this; } template <class c, class ... cs> stream& _dbg(const string& s, int i, int b, c arg, cs ... args) {
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


const int inf = 1000000000;
const int M = (1 << 16);
const int N = 1000005;
int n, i, j;

int t [N][5];

int a [N];
int b [N];
int c [N];

bool out [N];

int tree [M + M];

int query (int a, int b){
	a += M;
	b += M;
	assert(a <= b);
	int res = min(tree[a], tree[b]);
	while (a/2 != b/2){
		if (a%2 == 0) umin(res, tree[a + 1]);
		if (b%2 == 1) umin(res, tree[b - 1]);
		a /= 2;
		b /= 2;
	}
	return res;
}

void update (int u, int val){
	u += M;
	umin(tree[u], val);
	for (u /= 2; u >= 1; u /= 2)
		tree[u] = min(tree[u + u], tree[u + u + 1]);
}

void relax (int x1, int x2, int x3){
	
	for (i=0; i<n; i++){
		a[i] = t[i][x1];
		b[i] = t[i][x2];
		c[i] = t[i][x3];
	}

	vector <int> ord;

	for (i=0; i<n; i++)
		ord.pb(i);

	sort(all(ord), [] (int x, int y){
		return a[x] < a[y];
		});

	for (i=0; i<M+M; i++)
		tree[i] = inf;

	for (int i : ord){
		int x = b[i];
		int y = c[i];
		int res = query(0, x - 1);
		if (res < y)
			out[i] = true;
		update(x, y);
	}
}

void solve (){
	scanf ("%d", &n);

	for (i=0; i<n; i++)
		for (j=0; j<5; j++)
			scanf ("%d", &t[i][j]);

	for (i=0; i<n; i++)
		out[i] = false;
	
	relax(0, 1, 2);
	relax(0, 1, 3);
	relax(0, 1, 4);
	relax(0, 2, 3);
	relax(0, 2, 4);
	relax(0, 3, 4);
	relax(1, 2, 3);
	relax(1, 2, 4);
	relax(1, 3, 4);
	relax(2, 3, 4);

	int res = -1;
	for (i=0; i<n; i++)
		if (out[i] == false)
			res = i;

	if (res != -1)
		res += 1;

	printf ("%d\n", res);
}

int main (){
	int q = 1;
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
}