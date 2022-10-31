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

int mn[N], mx[N], cnt[N];
int a[N];
int events[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	forn(i, N) mn[i] = N, mx[i] = -1, events[i] = -1;
	int n, q;
	cin >> n >> q;
	forn(i, n) {
		cin >> a[i];
		mn[a[i]] = min(mn[a[i]], i);
		mx[a[i]] = max(mx[a[i]], i);
		cnt[a[i]]++;
	}
	forn(i, N) {
		if (mx[i] == -1) continue;
		events[mn[i]] = mx[i];
	}
	vector<pii> segments;
	int got = 0, start = -1, end = -1;
	forn(i, n) {
		if (!got) {
			start = i;
			end = events[i];
			got = 1;
		} 	
		if (end == i) {
			got = 0;
			segments.pb(mp(start, end));
		} else {
			end = max(end, events[i]);
		}
	}
	int ans = 0;
	for (pii p : segments) {
		int mxCnt = 0, len = p.snd - p.fst + 1;
		forab(i, p.fst, p.snd + 1) {
			mxCnt = max(mxCnt, cnt[a[i]]);
		}
		ans += len - mxCnt;
	}
	cout << ans << '\n';	
	return 0;
}