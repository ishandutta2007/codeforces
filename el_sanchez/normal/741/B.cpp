#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1e9;
const int MAXN = 1111;

int n, m, W;
int w[MAXN], b[MAXN], used[MAXN], dp[MAXN];
vi g[MAXN];
vi cur;
vector<vi> groups;
vector<pii> mv;

void dfs(int v) {
	cur.pb(v);
	used[v] = 1;
	for (auto z: g[v]) {
		if (!used[z]) {
			dfs(z);
		}
	}
}

void add(int cw, int cb) {
	mv.pb({cw, cb});	
}

int main() {

	cin >> n >> m >> W;
	forn(i, n) {
		scanf("%d", &w[i]);
	}
	forn(i, n) {
		scanf("%d", &b[i]);
	}
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);	
	}
	
	forn(i, n) {
		if (!used[i]) {
		 	cur.clear();
		 	dfs(i);
		 	groups.pb(cur);
		}
	}
	
	forn(i, W + 1) {
		dp[i] = -INF;
	}
	dp[0] = 0;
	
	for (int id = 0; id < (int)groups.size(); id++) {
		int sw = 0, sb = 0;
		mv.clear();
		for (auto girl: groups[id]) {
			add(w[girl], b[girl]);
			sw += w[girl];
			sb += b[girl];
		}
		add(sw, sb);
		
		for (int i = W; i >= 0; i--) {
			for (auto p: mv) {
				int dw = p.X, db = p.Y;
				if (i >= dw && dp[i] < dp[i - dw] + db) {
					dp[i] = dp[i - dw] + db;
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= W; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
	
    return 0;
}