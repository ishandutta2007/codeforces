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

const int N = 3005;

vector<pii> pars[N], al;
int cnt[N], p[N], c[N], used[N], cur[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, n) {
		cin >> p[i] >> c[i];
		pars[p[i]].pb(mp(c[i], i));
		if (p[i] != 1) al.pb(mp(c[i], i));
	}
	sort(all(al));
	forab(i, 2, m + 1) sort(all(pars[i]));
	ll ans = 1e18 + 100;
	for (int win = max(1, cnt[1]); win <= n; win++) {
		forab(i, 1, m + 1) {
			cnt[i] = 0;
			cur[i] = 0;
		}
		forn(i, n) {
			cnt[p[i]]++;
			used[i] = 0;
		}
		ll now = 0;
		int got = cnt[1];
		forab(i, 2, m + 1) {
			while (cnt[i] >= win) {
				cnt[i]--;
				int x = pars[i][cur[i]].fst;
				now += x;
				got++;
				used[pars[i][cur[i]].snd] = 1;
				cur[i]++;
			}
		}
		int t = 0;
		while(got < win) {
			if (!used[al[t].snd]) {
				got++;
				now += al[t].fst;
			} 
			t++;
		}
		ans = min(ans, now);
	}
	cout << ans << '\n';
	return 0;
}