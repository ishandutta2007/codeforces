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

pii a[N];
bool can[N][2], canSuf[N][2];
vector<int> ans[2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x[2];
	cin >> n >> x[0] >> x[1];
	forn(i, n) {
		cin >> a[i].fst;
		a[i].snd = i;
	}
	sort(a, a + n);
	fornr(i, n) {
		int cur = a[i].fst;
		forn(j, 2) {
			int num = (x[j] + cur - 1) / cur;
			if (i + num <= n) {
				can[i][j] = true;
			} else {
				can[i][j] = false;
			}
			canSuf[i][j] = can[i][j] | canSuf[i + 1][j];
		}
	}
	forn(i, n) {
		forn(j, 2) {
			if (can[i][j]) {
				int cur = a[i].fst;
				int num = (x[j] + cur - 1) / cur;
				if (canSuf[i + num][1 - j]) {
					cout << "Yes\n";
					int pos = i + num;
					while(!can[pos][1 - j]) pos++;
					forn(k, num) ans[j].pb(a[i + k].snd + 1);
					forab(k, pos, n) ans[1 - j].pb(a[k].snd + 1);
					cout << sz(ans[0]) << " " << sz(ans[1]) << '\n';
					for(int t : ans[0]) cout << t << " ";
					cout << '\n';
					for(int t : ans[1]) cout << t << " ";
					cout << '\n';
					return 0;
				}
			}
		}
	}
	cout << "No\n";
	return 0;
}