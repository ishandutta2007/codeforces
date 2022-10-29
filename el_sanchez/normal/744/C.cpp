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
const int MAXN = 16;
const int MAXSH = 133;
const int MAXK = 1 << MAXN;

int n;
int c[MAXN], a[2][MAXN], sum[2];
int ans, dp[MAXK][MAXSH];
int mtype[2][MAXK];
int fr[MAXK][MAXN], sz[MAXK];

int main() {
	
	scanf("%d\n", &n);
	forn(i, n) {
		char t;
		scanf("%c %d %d\n", &t, &a[0][i], &a[1][i]);
		c[i] = (t == 'R' ? 0 : 1);	
	}
	
	forn(id, 2) {
		forn(i, n) {
			sum[id] += a[id][i];
		}
	}
	
	forn(mask, 1 << n) {
		sz[mask] = 0;
		forn(i, n) {
			if ((mask >> i) & 1) {
				mtype[c[i]][mask]++;					
			} else {
				fr[mask][sz[mask]++] = i;				
			}
		}
	}
	
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	int i, npx, npy, nmask;
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int px = 0; px < MAXSH; px++) {
			if (dp[mask][px] != -1) {
				for (int pos = 0; pos < sz[mask]; pos++) {
					i = fr[mask][pos];
					//assert(((mask >> i) & 1) == 0);
					
					npx = px + mtype[0][mask] - max(mtype[0][mask] - a[0][i], 0);
					npy = dp[mask][px] + mtype[1][mask] - max(mtype[1][mask] - a[1][i], 0);
					nmask = mask | (1 << i);
					 
					if (dp[nmask][npx] < npy) {
						dp[nmask][npx] = npy;
					}
				}
			}
		}
	}

	int ans = INF;
	int f = (1 << n) - 1;
	for (int px = 0; px < MAXSH; px++) {
		if (dp[f][px] != -1) {
			int py = dp[f][px];
			//cout << px << ' ' << py << '\n';

			ans = min(ans, max(sum[0] - px, sum[1] - py));	
		}
	}
	ans += n;
	
	cout << ans << '\n';
	
    return 0;
}