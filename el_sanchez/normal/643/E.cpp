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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 500005;
const int C = 46;

int n, q;
ld dp[MAXN][C + 1];
ld old[C + 3][C + 3];
vi g[MAXN];
int par[MAXN];
ld ans;           

void calc(int v, int ch, int maxH) {
	if (v == -1)
		return;
	if (maxH == C)
		return;

	if (maxH == 0) {
		old[0][0] = dp[v][0];
	    dp[v][0] /= 2;
	} else {
	    old[maxH][maxH] = dp[v][maxH];
	    dp[v][maxH] /= (ld)1.0 + old[maxH - 1][maxH - 1];
		dp[v][maxH] *= (ld)1.0 + dp[ch][maxH - 1];	
	}
	
	calc(par[v], v, maxH + 1);	
}

int main() {

	cin >> q;
	n = 1;
	par[0] = -1;
	
	forn(i, C)
		dp[0][i] = 1;
	
	int tt, v;
	forn(ii, q) {
		scanf("%d", &tt);		
		if (tt == 1) {
			scanf("%d", &v);
			v--;
			g[v].pb(n);
			par[n] = v;
			
			forn(i, C)
				dp[n][i] = 1;
	
			calc(v, n, 0);
			n++;
		} else {
			scanf("%d", &v);
			v--;

			ans = C;
			forn(i, C)
				ans -= dp[v][i];

			//cout << ans << '\n';
			printf("%.8f\n", (double)ans);	
		}
	}
	
	//cerr << (double)clock() / CLOCKS_PER_SEC << endl;
	
	return 0;
}