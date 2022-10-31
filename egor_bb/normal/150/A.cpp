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

typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	LL q;
	cin >> q;
	vector <LL> primes, count;
	for(LL i = 2; i * i	<= q; i++) {
		if (q % i == 0) {
			primes.pb(i);
			count.pb(0);
			while(q % i == 0)
				count.back()++, q /= i;
		}
	}
	if (q > 1)
		primes.pb(q), count.pb(1);
	if (!sz(primes) || (sz(primes) == 1 && count[0] == 1)) {
		cout << 1 << '\n' << 0 << '\n';
	} else if ((sz(primes) == 1 && count[0] == 2) || (sz(primes) == 2 && count[0] == 1 && count[1] == 1)) {
		cout << 2 << '\n';
	} else if (sz(primes) == 1) {
		cout << 1 << "\n" << primes[0] * primes[0] << '\n';
	} else 
		cout << 1 << "\n" << primes[0] * primes[1] << '\n';
	return 0;
}