#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX = 1e4 + 5;

int bits[2 * MAX], cnt[MAX];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, k, l;
	scanf("%d%d", &n, &k);
	forn(i, n)
		scanf("%d", &l), cnt[l]++;
	ll ans = 0;
	forn (i, 2 * MAX)
		bits[i] = __builtin_popcount(i);
	if (k == 0) {
		forn (i, MAX)
			ans += (cnt[i] * 1ll * (cnt[i] - 1)) / 2;
	} else {
	 	forn (i, MAX)
	 		forn (j, i)
	 			if (bits[i ^ j] == k)
	 				ans += cnt[i] * 1ll * cnt[j];
	}
	printf(I64 "\n", ans);
	return 0;
}