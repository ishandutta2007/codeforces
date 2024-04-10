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

pii a[N];
int inds[2 * N], mx;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		cin >> a[i].fst;
		a[i].snd = 2 * i + 1;
	}
	sort(a, a + n);
	reverse(a, a + n);
	forn(i, n - 1) {
		cout << a[i].snd << " " << a[i + 1].snd << '\n';
	}
	forn(i, n) inds[i] = a[i].snd;
	mx = n;
	for (int cur = 0; cur < n; cur++) {
		int len = a[cur].fst;
		int ind = a[cur].snd, nxtInd = ind + 1;
		int nxt = cur + len - 1;
		cout << inds[nxt] << " " << nxtInd << '\n';
		if (nxt + 1 == mx) {
			inds[mx++] = nxtInd;
		}
	}
	return 0;
}