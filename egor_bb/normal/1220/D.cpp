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

const int N = 2e5 +100;

ll a[N];
vector<ll> cnt[61];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		cin >> a[i];
		int c = 0;
		ll tmp = a[i];
		while(tmp % 2 == 0) {
			tmp /= 2;
			c++;
		}
		cnt[c].pb(a[i]);
	}
	int ans = 0, anspos = -1;
	forn(i, 61) {
		if (ans < sz(cnt[i])) {
			ans = sz(cnt[i]);
			anspos = i;
		}
	}
	cout << n - ans << '\n';
	forn(i, 61) {
		if (i == anspos) continue;
		for (ll x : cnt[i]) {
			cout << x << " ";
		}
	}
	cout << '\n';
	return 0;
}