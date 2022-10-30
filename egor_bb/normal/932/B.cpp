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

const int N = 1e6 + 100;

int a[N];

int calc(int x) {
	if (x < 10) return x;
	int ans = 1;
	while (x) {
		int s = x % 10;
		if (s) ans *= s;
		x /= 10;
	}
	return calc(ans);
}

vector<int> pos[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	forab(i, 1, N) {
		a[i] = calc(i);
		pos[a[i]].pb(i);
	}
	int n;
	cin >> n;
	forn(i, n) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << upper_bound(all(pos[k]), r) - lower_bound(all(pos[k]), l) << '\n';
	}
	return 0;
}