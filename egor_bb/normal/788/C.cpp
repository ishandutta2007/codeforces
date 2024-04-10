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

const int N = 5e5 + 100;
const int MAGIC = 1010;
const int INF = 1e9 + 7;

vector <int> down, up;
int dist_up[N], dist_down[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;	
	scanf("%d%d", &n, &k);
	forn(i, k) {
		int t; scanf("%d", &t);
		if (t == n) {
			cout << 1 << '\n';
			return 0;
		}
		if (t < n) {
			down.pb(n - t);
		} else {
			up.pb(t - n);
		}
	}
	if (sz(down) == 0 || sz(up) == 0) {
	       cout << -1 << '\n';
	       return 0;
	}
	sort(all(down));
	down.resize(unique(all(down)) - down.begin());
	sort(all(up));
	up.resize(unique(all(up)) - up.begin());
	forn(i, N) {
		dist_up[i] = dist_down[i] = INF;
	}
	dist_up[0] = dist_down[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		int dist = dist_down[t];
		for(int d : down) {
			if (t + d < N && dist_down[t + d] == INF) {
				dist_down[t + d] = dist + 1;
				q.push(t + d);
			}
		}
	}
	q.push(0);
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		int dist = dist_up[t];
		for(int d : up) {
			if (t + d < N && dist_up[t + d] == INF) {
				dist_up[t + d] = dist + 1;
				q.push(t + d);
			}
		}
	}
	int ans = INF;
	forab(i, 1, N) {
		ans = min(ans, dist_down[i] + dist_up[i]);
	}
	if (ans == INF) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
	return 0;
}