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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ordered_set = tree< pair <int,int>, null_type, less<pair <int,int> >, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 998244353;
const int N = 1000005;
int na, nb, i, j;
int a [N];
int b [N];
int pa [N];
int pb [N];
set < pair <int,int> > S;

void solve ()
	{
	scanf ("%d%d", &na, &nb);

	for (i=1; i<=na; i++)
		{
		pa[i] = 0;
		pb[i] = 0;
		}
	
	for (i=1; i<=na; i++)
		{
		scanf ("%d", &a[i]);
		pa[a[i]] = i;
		}

	for (i=1; i<=nb; i++)
		{
		scanf ("%d", &b[i]);
		pb[b[i]] = i;
		}

	S.clear();
	
	for (i=1; i<=na; i++)
		{
		if (pb[a[i]] == 0)
			S.insert({i, 0});
		else
			S.insert({i, pb[a[i]]});
		}

	ll out = 1;
	for (i=1; i<=nb; i++)
		{
		pair <int,int> p = {pa[b[i]], i};
		auto it = S.find(p);
		
		bool A, B;
		
		if (it == S.begin() || prev(it)->s != 0)
			A = false;
		else
			A = true;

		if (next(it) == S.end() || next(it)->s != 0)
			B = false;
		else
			B = true;
		
		if (A == false && B == false)
			{
			printf ("0\n");
			return;
			}

		if (A == true && B == true)
			(out *= 2) %= mod;

		S.erase(it);
		}

	printf ("%lld\n", out);
	}

int main ()
	{
	int q;
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}