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
const int INF = 1E9;
const int MAXN = 5050;
const ll LINF = 1E18;

int n, s, f;
int x[MAXN], a[MAXN], b[MAXN], c[MAXN], d[MAXN], dist[MAXN];
ll dp[2][MAXN][2][2];

bool upd(ll &x, ll y) {
	if (x > y) {
		x = y;
		return 1;
	}
	return 0;
}

int main() {

	cin >> n >> s >> f;
	s--, f--;
	forn(i, n) cin >> x[i];
	forn(i, n - 1)
		dist[i] = x[i + 1] - x[i];
		
	forn(i, n) cin >> a[i];
	forn(i, n) cin >> b[i];
	forn(i, n) cin >> c[i];
	forn(i, n) cin >> d[i];
	
	forn(i, 2)
		forn(j, MAXN)
			forn(from, 2)
				forn(to, 2)
					dp[i][j][from][to] = LINF;
					
	dp[0][0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		int id = i & 1;
		int nid = id ^ 1;
								
		for (int j = 0; j <= n; j++)
			forn(from, 2)
				forn(to, 2) {
					ll cur = dp[id][j][from][to];
						
					if (cur < LINF) {
						if (i == s) {
							assert(!to);
							// ->
							upd(dp[nid][j][from][1], cur + d[i]);
							// <-
							if (j > 0)
								upd(dp[nid][j - 1][from][1], cur + c[i]);
							if (i == n - 1 && from)
								upd(dp[nid][j][0][0], cur + c[i]);
						} else if (i == f) {
							assert(!from);
							// ->
							upd(dp[nid][j][1][to], cur + b[i]);
							// <-
							if (j > 0)
								upd(dp[nid][j - 1][1][to], cur + a[i]);
							if (i == n - 1 && to)
								upd(dp[nid][j][0][0], cur + a[i]);
						} else {
							// ->
							upd(dp[nid][j + 1][from][to], cur + b[i] + d[i]);
							
							//connect two paths
							if (j > 1 || (j == 1 && from + to > 0))
								upd(dp[nid][j - 1][from][to], cur + a[i] + c[i]);
							if (i == n - 1 && from && to)
								upd(dp[nid][j][0][0], cur + a[i] + c[i]);
							
							//-> ->
							if (j + to)
								upd(dp[nid][j][from][to], cur + a[i] + d[i]);
								
							//<- <-
							if (j + from)
								upd(dp[nid][j][from][to], cur + b[i] + c[i]);
						 }
					}
				}

		for (int j = 0; j <= n; j++)
			forn(from, 2)
				forn(to, 2) {
					dp[id][j][from][to] = LINF;			
					if (dp[id ^ 1][j][from][to] < LINF)
						dp[id ^ 1][j][from][to] += 1ll * (2 * j + from + to) * dist[i];	
				}
				
	}
	
	cout << dp[n & 1][0][0][0] << '\n';
		
	return 0;
}