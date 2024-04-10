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
const ld eps = 1e-9;
const int INF = 1E9; 

const int MAXMAX = 200500;
const int MAXN = 2016;
const int MAXK = 23;        
const int MOD = (int)1E9 + 7;

void Add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;	
}

void Sub(int &x, int y) {
	x += MOD - y;
	if (x >= MOD)
		x -= MOD;	
}

int inv(int x) {
	int res = 1, pw = MOD - 2;
	while (pw > 0) {
		if (pw & 1)
			res = (1ll * res * x) % MOD;
		pw >>= 1;
		x = (1ll * x * x) % MOD;
	}
	return res;
}

int n, m, k, s;
int K;
pii anom[MAXN];
int dp[MAXK][MAXN], numPaths[MAXN][MAXN];
int f[MAXMAX], invf[MAXMAX];
int all, rest;
int add;

int cnk(int n, int k) {
	return 1ll * f[n] * invf[k] % MOD * 1ll * invf[n - k] % MOD;	
}

int calcPaths(int x, int y) {
	if (x < 0 || y < 0)
		return 0;
	return cnk(x + y, x);
}

int main() {
	
	f[0] = invf[0] = 1;
	forab(i, 1, MAXMAX) {
		f[i] = 1ll * f[i - 1] * i % MOD;
		invf[i] = inv(f[i]);
	}
	
    /*
	n = 1000000;
	for (int i = 1; i <= 22; i++) {
		n = (n + 1) / 2;
		cout << i << ' ' << n << '\n';
	}
	*/
	cin >> n >> m >> k >> s;
	add = 0;
	K = 0;
	forn(i, k) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		if ((x == 0 && y == 0) || (x == n - 1 && y == m - 1)) {
			add++;
		} else {
			anom[K++] = {x, y};	
		}                      		
	}
	
	anom[K++] = {0, 0};
	anom[K++] = {n - 1, m - 1};
	k = K;
	sort(anom, anom + k);
	memset(dp, 0, sizeof(dp));
	assert(anom[0].X == 0 && anom[0].Y == 0);
	dp[add][0] = 1;
	
	for (int i = 0; i < k; i++)
		for (int j = i + 1; j < k; j++)
			numPaths[i][j] = calcPaths(anom[j].X - anom[i].X, anom[j].Y - anom[i].Y);
/*
	forn(i, k)
		forab(j, i + 1, k)
			cout << numPaths[i][j] << '\n';
*/					
	for (int lvl = add; lvl < MAXK - 1; lvl++) {
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < i; j++) {
				if (anom[j].X <= anom[i].X && anom[j].Y <= anom[i].Y) {
					Add(dp[lvl + 1][i], 1ll * dp[lvl][j] * numPaths[j][i] % MOD);
					Sub(dp[lvl + 1][i], 1ll * dp[lvl + 1][j] * numPaths[j][i] % MOD);
				}
			}
		}
	} 	
	/*
	forab(vis, 1, 4)
		forn(i, k)
			printf("%d: to %d -- %d paths\n", vis - 1, i, dp[vis][i]);	
	*/
	int ans = 0;
	all = cnk(n + m - 2, n - 1);
	rest = all;
	int S = s;
	for (int vis = 1; vis < MAXK; vis++) {
		//cout << "---\n";
		int cur = dp[vis][k - 1];
		//cout << rest << ": " << cur << '\n';
		
		Add(ans, 1ll * cur * S % MOD);
		Sub(rest, cur);
		S = (S + 1) / 2;
	}
	
	Add(ans, 1ll * rest * 1 % MOD);
	
	ans = 1ll * ans * inv(all) % MOD;
	
	cout << ans << '\n';
	
	return 0;
}