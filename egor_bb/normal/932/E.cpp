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
const int N = 5e3 + 100;

int add(int a, int b) {
	a += b;
	return a >= MOD ? a - MOD : a;
}

int mult(int a, int b) {
	return int((a * 1ll * b) % MOD);
}

int pow(int x, int d) {
	if (d == 0) return 1;
	int t = pow(x, d / 2);
	t = mult(t, t);
	if (d & 1) t = mult(t, x);
	return t;
}

int coeff[N], newCoeff[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	coeff[0] = 1;
	forab(c, 1, k + 1) {
		forn(i, N) newCoeff[i] = 0;
		forn(d, k + 1) {
			int degZ = d, deg1Z = n - d;
			newCoeff[d] = add(newCoeff[d], mult(degZ, coeff[d]));
			newCoeff[d + 1] = add(newCoeff[d + 1], mult(deg1Z, coeff[d]));
		}
		swap(coeff, newCoeff);
	}
	int ans = 0;
	forn(i, N) {
		ans = add(ans, mult(coeff[i], pow(2, n - i)));
	}
	cout << ans << '\n';
	return 0;
}