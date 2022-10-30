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



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	if (n <= 3) {
		cout << -1 << '\n';
		return 0;
	}
	if (k == 1 || k > 3) {
		cout << -1 << '\n';
		return 0;
	}
	if (k == 2) {
		if (n == 4) {
			cout << -1 << '\n';
		} else {
			cout << n - 1 << '\n';
			for (int i = 1; i + 1 <= n; i++) {
				cout << i << " " << i + 1 << '\n';
			}
		}
		return 0;
	} else {
		int num = n - 2;
		int cnt = num * (num - 1) / 2;
		cnt += num;
		cout << cnt << '\n';
		for (int i = 1; i <= num; i++) {
			for (int j = i + 1; j <= num; j++) {
				cout << i << " " << j << '\n';
			}
		} 
		cout << 1 << " " << num + 1 << '\n';
		for (int i = 2; i <= num; i++) {
			cout << i << " " << n << '\n';
		}
		return 0;
	}
	return 0;
}