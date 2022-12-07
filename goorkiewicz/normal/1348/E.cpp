#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const ll inf = 1000000000000000005;
const int N = 505;
int n, i, k, a, b, aa, bb, full, rest;
int A [N];
int B [N];
ll S [N];
ll dp [N][N];

int main ()
	{
	scanf ("%d%d", &n, &k);
	
	for (i=1; i<=n; i++)
		scanf ("%d%d", &A[i], &B[i]);
	
	for (i=1; i<=n; i++)
		S[i] = S[i-1] + A[i] + B[i];

	for (i=0; i<N; i++)
		for (a=0; a<N; a++)
			dp[i][a] = -inf;
	
	dp[1][0] = 0;

	for (i=1; i<=n; i++)
		{
		full = (A[i] + B[i]) / k;
		rest = (A[i] + B[i]) % k;
		
		for (a=0; a<k; a++)
			{
			if (dp[i][a] == -inf)
				continue;

			b = S[i-1] - a - dp[i][a] * k;
			
			for (aa=0; aa<=rest && aa<=A[i]; aa++)
				{
				bb = rest - aa;
				if (bb <= B[i])
					umax(dp[i+1][(a+aa)%k], dp[i][a] + (a+aa)/k + (b+bb)/k + full);
				}
			
			if (A[i] + B[i] < rest + k)
				continue;

			for (aa=0; aa<=rest+k && aa<=A[i]; aa++)
				{
				bb = rest + k - aa;
				if (bb <= B[i])
					umax(dp[i+1][(a+aa)%k], dp[i][a] + (a+aa)/k + (bb+b)/k + full - 1);
				}
			}
		}
	
	ll out = 0;
	for (i=0; i<k; i++)
		umax(out, dp[n+1][i]);
	printf ("%lld\n", out);

	return 0;
	}