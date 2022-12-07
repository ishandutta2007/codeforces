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


const ll mod = 1000000007;
const ll p = 29;
const int N = 2000005;

int n, q, i, j;
char str [N];
string t, a;
ll pw [N];
ll pw2 [N];
ll sufa [N];
ll sufb [N];
bool pre [N];
bool suf [N];
int cnt [100005][30];
vector <string> s;

ll H (ll* suf, int a, int d) {
	return (suf[a] - ((suf[a + d] * pw[d]) % mod) + mod) % mod;
	}

void solve ()
	{
	int k;
	scanf ("%d", &k);
	scanf ("%s", str);
	a = str;
	
	int rank = 0;
	while (ss(s[rank]) < ss(a))
		rank++;

	if (k < rank)
		{
		printf ("0\n");
		return;
		}

	string b = s[rank];

	assert(ss(b) >= ss(a));
	
	sufa[ss(a)] = 0;
	for (i=ss(a) - 1; i>=0; i--)
		sufa[i] = (sufa[i + 1] * p + a[i] - ('a' - 1)) % mod;

	sufb[ss(b)] = 0;
	for (i=ss(b) - 1; i>=0; i--)
		sufb[i] = (sufb[i + 1] * p + b[i] - ('a' - 1)) % mod;
	
	assert(H(sufa, 0, ss(a)) == sufa[0]);

	int occ = 0;
	for (i=0; i+ss(a) <= ss(b); i++)
		if (H(sufb, i, ss(a)) == sufa[0])
			occ++;
	
	if (k == rank)
		{
		printf ("%d\n", occ);
		return;
		}
	
	pre[0] = true;
	suf[0] = true;
	for (i=1; i<ss(a); i++)
		{
		pre[i] = (H(sufb, ss(b) - i, i) == H(sufa, 0, i));
		suf[i] = (H(sufb, 0, i) == H(sufa, ss(a) - i, i));
		}
	
	ll out = (occ * pw2[k - rank]) % mod;
	
	for (i=0; i<ss(a); i++)
		{
		if (pre[i] == false)
			continue;
		if (suf[ss(a) - i - 1] == false)
			continue;

		ll res = cnt[k][a[i]];
		res -= cnt[rank][a[i]] * pw2[k - rank];
		out += res;
		out %= mod;
		}
	
	out += mod;
	out %= mod;
	
	printf ("%lld\n", out);
	}

int main ()
	{
	pw[0] = 1;
	for (i=1; i<N; i++)
		pw[i] = pw[i - 1] * p % mod;
	
	pw2[0] = 1;
	for (i=1; i<N; i++)
		pw2[i] = pw2[i - 1] * 2 % mod;

	scanf ("%d%d", &n, &q);
	scanf ("%s", str); s.pb(str);
	scanf ("%s", str); t = str;
	
	while (t.size() < 100)
		t.pb('z' + 1);
	
	n = ss(t);
	
	for (i=0; true; i++)
		{
		if (s[i].size() >= 1000000)
			break;
		s.pb(s[i] + t[i] + s[i]);
		}
	
	assert(ss(s.back()) >= 1000000);

	for (i=1; i<=n; i++)
		for (char c='a'; c<='z'; c++)
			{
			cnt[i][c] = 2 * cnt[i - 1][c];
			if (t[i - 1] == c)
				cnt[i][c] += 1;
			cnt[i][c] %= mod;
			}
	
	while (q--)
		solve();
	
	return 0;
	}