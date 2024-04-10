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
const int INF = 1e9 + 7;

vector<int> got[60];

vector<int> g[N];

int d[N];
ll a[N];
int q[N * 10];

int bfs(int s, int finish, int n) {
	//cout << "!" << s << " " << finish << '\n';
	forn(i, n) d[i] = INF;
	q[0] = s;
	d[s] = 0;
	int cur = 0, size = 1;
	while(cur != size) {
		int v = q[cur]; 
		cur++;
		for (int to : g[v]) {
			if (v == s && to == finish) continue;
			if (v == finish && to == s) {
				return d[v] + 1;
			}
			if (d[to] > d[v] + 1) {
				d[to] = d[v] + 1;
				q[size++] = to;
			}
		}
	}
	return INF;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		cin >> a[i];
		forn(j, 60) {
			if (a[i] & (1ll << j)) {
				got[j].pb(i);
				if (sz(got[j]) > 2) {
					cout << 3 << '\n';
					return 0;
				}
			}
		}
	}
	forn(j, 60) {
		if (sz(got[j]) == 2) {
			g[got[j][0]].pb(got[j][1]);
			g[got[j][1]].pb(got[j][0]);
			//cout << got[j][0] << " " << got[j][1] << '\n';
		}
	}
	int ans = INF;
	forn(i, n) {
		forn(j, sz(g[i])) {
			ans = min(ans, bfs(i, g[i][j], n));
		}
	}
	if (ans == INF) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
	return 0;
}