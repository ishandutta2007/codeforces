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

const int N = (1 << 18);

int cnt[N];

void add(ll x, int d) {
	ll num = 0, k = 0;
	while(x) {
		num += ((x & 1) << k);
		x /= 10;
		k++;
	}
	cnt[num] += d;
}

int get(ll x) { 
	ll num = 0, k = 0;
	while(x) {
		num += ((x & 1) << k);
		x /= 10;
		k++;
	}
	return cnt[num];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		char c;
		cin >> c;
		if (c == '+') {
			ll a; cin >> a;
			add(a, 1);
		} else if (c == '-') {
			ll a; cin >> a;
			add(a, -1);
		} else {
			ll a; cin >> a;
			cout << get(a) << '\n';
		}
	}
	return 0;
}