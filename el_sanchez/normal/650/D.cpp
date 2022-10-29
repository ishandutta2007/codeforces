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
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 400500;
    
int n, m;
int h[MAXN];
int curH[MAXN];
vector<pii> q[MAXN];
int len;
int dp[2][MAXN], newdp[2][MAXN];
int imp[MAXN], quant[MAXN];
int ans[MAXN];

int main() {

	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d", &h[i]);
		
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		q[a].pb({b, i});	
	}

	memset(dp, 0, sizeof(dp));
		
	forn(id, 2) {
		curH[0] = -2 * INF;
		for (int i = 1; i <= n; i++)
			curH[i] = 2 * INF;
		
		//cout << "---\n";
		for (int i = 0; i < n; i++) {
			//for (int j = 0; j <= n; j++)
			//	cout << curH[j] << " \n"[j == n];
				
			int pos;
			
			for (auto p: q[i]) {
				pos = lower_bound(curH, curH + n + 1, p.X) - curH;
				pos--;
				assert(pos >= 0);
				newdp[id][p.Y] = pos + 1;
			}
			
			pos = lower_bound(curH, curH + n + 1, h[i]) - curH;
			pos--;
			assert(pos >= 0);
			curH[pos + 1] = min(curH[pos + 1], h[i]);
			dp[id][i] = pos + 1;
		}
		
		reverse(h, h + n);
		reverse(q, q + n);
	    forn(i, n)
	    	h[i] *= -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < (int)q[i].size(); j++)
				q[i][j].X *= -1;	
	}
	
	reverse(dp[1], dp[1] + n);
	/*
	forn(id, 2)
		forn(i, n)
			cout << dp[id][i] << " \n"[i == n - 1];

	forn(id, 2)
		forn(i, m)
			cout << newdp[id][i] << " \n"[i == m - 1];
	*/		
	len = 0;
	forn(i, n)
		len = max(len, dp[0][i]);
		
	memset(ans, -1, sizeof(ans));
	
	forn(i, m)
		if (newdp[0][i] + newdp[1][i] - 1 >= len)
			ans[i] = newdp[0][i] + newdp[1][i] - 1;
			
	forn(i, n)
		if (dp[0][i] + dp[1][i] - 1 == len) {
			imp[i] = 1;
			quant[dp[0][i]]++;	
		}
		
	for (int i = 0; i < n; i++)
		for (auto p: q[i]) {
			if (ans[p.Y] == -1) {
				if (imp[i] && quant[dp[0][i]] == 1) {
				    ans[p.Y] = len - 1;
				} else {
					ans[p.Y] = len;
				}
			}
		}
		
	forn(i, m)
		printf("%d\n", ans[i]);
	
	return 0;	
}