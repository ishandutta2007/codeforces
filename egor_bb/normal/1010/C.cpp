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

const int N = 1e5 + 1;

int a[N], got[N], used[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int gcd = -1;
	forn(i, n) {
		cin >> a[i];
		a[i] %= k;
		if (gcd == -1 && a[i]) gcd = a[i];
		else if (a[i]) gcd = __gcd(a[i], gcd); 
	}
	used[0] = 1;
	if (gcd == -1) {
		cout << 1 << '\n' << 0 << '\n';
		return 0;
	}
	vector<int> ans;
	ans.pb(gcd);
	for (int j = (2 * gcd) % k; j != gcd; j = (j + gcd) % k) {
		ans.pb(j);
	}
	sort(all(ans));
	cout << sz(ans) << '\n';
	for(int x : ans) cout << x << " ";
	cout << '\n';
	
	return 0;
}