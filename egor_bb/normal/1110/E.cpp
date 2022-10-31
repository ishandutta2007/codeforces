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

const int N = 1e5 + 100;

ll a[N], b[N];
ll d1[N], d2[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		cin >> a[i];
		if (i > 0) d1[i - 1] = a[i] - a[i - 1];	
	}
	forn(i, n) {
		cin >> b[i];
		if (i > 0) d2[i - 1] = b[i] - b[i - 1];	
	}
	if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
		cout << "No\n";
		return 0;
	}
	sort(d1, d1 + n - 1);
	sort(d2, d2 + n - 1);
	forn(i, n - 1) {
		if (d1[i] != d2[i]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}