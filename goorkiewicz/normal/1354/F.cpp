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

const ll inf = 1000000000000000005;
const int N = 105;
int n, i, j, k;
ll a [N];
ll b [N];
ll dp [N][N];
bool fr [N][N];
vector <int> ord;

void solve ()
	{
	scanf ("%d%d", &n, &k);

	for (i=1; i<=n; i++)
		scanf ("%lld%lld", &a[i], &b[i]);

	ord.clear();
	for (i=1; i<=n; i++)
		ord.pb(i);

	sort(all(ord), [] (int x, int y) { return b[x] < b[y]; });
	
	for (i=0; i<=n; i++)
		for (j=0; j<=k; j++)
			dp[i][j] = -inf;
	
	dp[0][0] = 0;

	for (i=1; i<=n; i++)
		{
		int id = ord[i-1];
		for (j=0; j<=k; j++)
			{
			dp[i][j] = dp[i-1][j];
			fr[i][j] = false;
			
			ll val = dp[i-1][j] + (k-1) * b[id];
			if (dp[i][j] < val)
				{
				dp[i][j] = val;
				fr[i][j] = false;
				}
			
			if (j > 0)
				{
				ll val = dp[i-1][j-1] + (j-1) * b[id] + a[id];
				if (val > dp[i][j])
					{
					dp[i][j] = val;
					fr[i][j] = true;
					}
				}
			}
		}

	vector <int> A, B;
	
	j = k;
	for (i=n; i>=1; i--)
		{
		int id = ord[i-1];
		if (fr[i][j] == true)
			{
			A.pb(id);
			j--;
			}
		else
			B.pb(id);
		}
	
	reverse(all(A));

	printf ("%d\n", n + n - k);
	
	for (i=0; i+1<ss(A); i++)
		printf ("%d ", A[i]);
	for (i=0; i<ss(B); i++)
		printf ("%d -%d ", B[i], B[i]);
	printf ("%d\n", A.back());
	}

int main ()
	{
	int q = 1;
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}