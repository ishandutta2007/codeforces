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


const vector < vector <int> > elo = {
{1, 3, 6, 7, 2, 5},
{3, 6},
{1, 3, 4, 5, 7},
{1, 3, 4, 6, 7},
{2, 3, 4, 6},
{1, 2, 4, 6, 7},
{1, 2, 4, 5, 6, 7},
{1, 3, 6},
{1, 2, 3, 4, 5, 6, 7},
{1, 2, 3, 4, 6, 7}};

const int N = 2005;
int n, i, j, k, c, x;
int mask [10];
char str [10];
int tab [N];
int out [N];
bool dp [N][N];

void solve ()
	{
	scanf ("%d%d", &n, &k);
	
	for (i=0; i<=9; i++)
		for (int a : elo[i])
			mask[i] ^= (1<<(a-1));
	
	for (i=1; i<=n; i++)
		{
		scanf ("%s", str);
		for (j=0; str[j]!=0; j++)
			if (str[j] == '1')
				tab[i] ^= (1<<j);
		}

	reverse(tab+1, tab+n+1);
	
	dp[0][0] = true;
	
	for (i=1; i<=n; i++)
		for (x=0; x<=9; x++)
			{
			if ((mask[x]&tab[i]) != tab[i])
				continue;
			c = __builtin_popcount(mask[x]^tab[i]);
			for (j=c; j<=k; j++)
				dp[i][j] |= dp[i-1][j-c];
			}

//	for (i=1; i<=n; i++)
//		for (j=1; j<=k; j++)
//			dbg(i, j, dp[i][j]);

	if (dp[n][k] == false)
		{
		printf ("-1\n");
		return;
		}

	for (i=n; i>=1; i--)
		{
		for (x=9; x>=0; x--)
			{
			if ((mask[x]&tab[i]) != tab[i])
				continue;
			c = __builtin_popcount(mask[x]^tab[i]);
			if (k-c >= 0 && dp[i-1][k-c] == true)
				{
				out[i] = x;
				k -= c;
				break;
				}
			}
		}

	reverse(out+1, out+n+1);
	
	for (i=1; i<=n; i++)
		printf ("%d", out[i]);
	printf ("\n");
	}


int main ()
	{
	int q = 1;
	while (q--)
		solve();
	return 0;
	}