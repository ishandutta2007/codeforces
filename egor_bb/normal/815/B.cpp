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

const int N = 2e5 + 100;
const int MOD = 1e9 + 7;

int mul(int a, int b) {
	return int((((a * 1ll * b) % MOD) + MOD) % MOD);
}

int sum(int a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int pow(int x, int k) {
	if (k == 0)
		return 1;
	int t = pow(x, k / 2);
	return (k & 1) ? mul(t, mul(t, x)) : mul(t, t);
}

int rev(int x) {
	return pow(x, MOD - 2);
}

int sign[N], fact[N], a[N], b[N], in[N];

void calc() {
	fact[0] = fact[1] = 1;
	forab(i, 2, N) 
		fact[i] = mul(fact[i - 1], i);
}

int cnk(int n, int k) {
	return mul(fact[n], mul(rev(fact[k]), rev(fact[n - k])));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	calc();
	int n;
	cin >> n;
	sign[n] = 1;
	fornr(i, n) {
		sign[i] = sign[i + 1];
		if ((i + 1) % 2 == 0) {
			sign[i] *= -1;
		}
	}
	forn(i, n) {
		cin >> in[i];
	}
	
	int m = n;
	while(m % 4 != 1) {
		m--;
	}
	for(int i = 0; i < m; i += 2) {
		a[i] = cnk(m / 2, i / 2);
	}
	
	forab(i, m, n) {
		forn(j, N)
			b[j] = 0;
		forn(j, i) {
			int s = sign[i + 1];
			if (j & 1)
				s *= -1;
			b[j] = sum(b[j], a[j]);
			b[j + 1] = sum(b[j + 1], mul(a[j], s));
		} 		
		swap(b, a);
	}
	int ans = 0;
	forn(i, n) {
		ans = sum(ans, mul(a[i], in[i]));
	}
	cout << ans << '\n';
	return 0;
}