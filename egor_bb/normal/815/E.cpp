#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

ll dc(ll len, ll k) {
	ll mid = (len + 1) / 2;
	if (k == 1)
		return mid;
	k--;
	ll leftlen = mid - 1, rightlen = len - mid;
	map<pair<pll, ll>, ll> segments;
	if (leftlen)
		segments[mp(mp(-(leftlen - 1) / 2, 0), leftlen & 1)]++;
	if (rightlen)
		segments[mp(mp(-(rightlen - 1) / 2, 1), rightlen & 1)]++;
	ll gotleft = 0, gotright = 0;
	while(1) {
		int type = segments.begin()->fst.fst.snd;
		ll l = -segments.begin()->fst.fst.fst;
		l *= 2;
		if (segments.begin()->fst.snd)
			l++;
		else
			l += 2;
		ll cnt = segments.begin()->snd;
		segments.erase(segments.begin());
		ll sh = (l - 1) / 2;
		if (l == 2) {
			if (type == 0) {
				gotleft += cnt * 2;
			} else {
				gotright += cnt * 2;
			}
		} else {
			if (l > 1) {
				segments[mp(mp(-(sh - 1) / 2, type), sh & 1)] += cnt;
				sh = l - sh - 1;
				segments[mp(mp(-(sh - 1) / 2, type), sh & 1)] += cnt;
			}
			if (type == 0) {
				gotleft += cnt;
			} else {
				gotright += cnt;
			}
		}
		if (gotleft + gotright >= k) {
			if (type)
				return mid + dc(rightlen, k - gotleft);
			else
				return dc(leftlen, k - gotright);
		}
	}
}

ll solve(ll n, ll k) {
	if (k == 1)
		return 1;
	if (k == 2)
		return n;
	n -= 2; k -= 2;
	return 1 + dc(n, k);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	cout << solve(n, k) << '\n';
	return 0;
}