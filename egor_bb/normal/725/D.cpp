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

const int N = 3e5 + 100;
pair<ll,ll> a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		cin >> a[i].fst >> a[i].snd;
	}
	sort(a + 1, a + n);
	int p = n - 1;
	set<pair<ll,int>> s;
	int best = n, cnt = 0;
	while(1) {
		while(p > 0 && a[p].fst > a[0].fst) {
			s.insert(mp(a[p].snd - a[p].fst + 1, p));
			cnt++;
			p--;
		}
		best = min(best, cnt + 1);
		if (a[0].fst < s.begin()->fst) {
			break;
		}
		a[0].fst -= s.begin()->fst;
		s.erase(s.begin());
		cnt--;
	}	
	cout << best << '\n';
	return 0;
}