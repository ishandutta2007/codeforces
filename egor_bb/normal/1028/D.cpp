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


const int MOD = 1e9 + 7;

int l = 0, r = MOD;
set<int> vals;

int get_low(int x) {
	auto it = vals.lower_bound(x);
	if (it == vals.begin()) return 0;
	it--;
	return *it;
}

int get_up(int x) {
	auto it = vals.upper_bound(x);
	if (it == vals.end()) return MOD;
	return *it;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 1;
	int mult = 1;
	forn(i, n) {
		string t;
		int x;
		cin >> t >> x; 
		if (t == "ADD") {
			vals.insert(x);
			if (l < x && x < r) {
				mult = (mult + 1) % MOD;
			}
		} else {
			mult = 1;
			if (l < x && x < r) {
				l = get_low(x);
				r = get_up(x);
				ans = (ans * 2) % MOD;
				vals.erase(x);
			} else if (x < l || r < x) {
				cout << 0 << '\n';
				return 0;
			} else {
				l = get_low(x);
				r = get_up(x);
				vals.erase(x);
			}
		}
	}
	cout << (ans * 1ll * mult) % MOD << '\n';
	return 0;
}