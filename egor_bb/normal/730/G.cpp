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
	set <pair<ll,ll>> s;
	s.insert(mp(1, 1e18));
	int n;
	cin >> n;
	forn(i, n) {
		int day, d; cin >> day >> d;
		pair <ll, ll> ans = mp(-1ll, -1ll);
		for (auto p : s) {
			if (p.fst <= day && day + d <= p.snd)
				ans = p;
		}
		if (ans != mp(-1ll, -1ll)) {
			s.erase(ans);
			s.insert(mp(ans.fst, day));
			s.insert(mp(day + d, ans.snd));
			cout << day << " " << day + d - 1 << '\n';
			continue;
		}
		for (auto p : s) {
			if (p.snd - p.fst >= d) {
				ans = p;
				break;
			}
		}
		cout << ans.fst << " " << ans.fst + d - 1 << '\n';
		s.erase(ans);
		s.insert(mp(ans.fst + d, ans.snd));
	}
	return 0;
}