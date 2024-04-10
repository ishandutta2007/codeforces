#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 111;
const int MAXM = 111111;
    
int n, m;
int a[MAXN], lim;
ld dp[2][MAXM], sum[MAXM];

ld getSum(int L, int R) {
	ld res = sum[R];
	if (L > 0)
		res -= sum[L - 1];
	return res;	
}

int main() {

	cin >> n >> m;
	lim = 0;
	forn(i, n) {
		cin >> a[i];
		lim += a[i];
	}

	if (m == 1) {
		cout << 1 << '\n';
		return 0;
	}
	
	dp[0][0] = 1;
	int id = 0;
	for (int i = 0; i < n; i++) {
		id ^= 1;

		for (int j = 0; j < MAXM; j++)
			dp[id][j] = 0;

		sum[0] = dp[id ^ 1][0];
		forab(j, 1, MAXM)
			sum[j] = sum[j - 1] + dp[id ^ 1][j];

		for (int j = 1; j < MAXM; j++) {
			/*
			for (int k = 1; k <= m; k++)
				if (k != a[i] && j - k >= 0)
					dp[id][j] += dp[id ^ 1][j - k] / (m - 1);
			*/
			
			int R = j - 1;
			int L = max(0, j - m);
			dp[id][j] = getSum(L, R) / (m - 1);
			if (0 <= j - a[i])
				dp[id][j] -= dp[id ^ 1][j - a[i]] / (m - 1);
		}
	}
	
	ld totalProb = 0;
	
	for (int j = 0; j < lim; j++)
		totalProb += dp[id][j];

	ld ans = 1.0 + totalProb * (m - 1);

	cout.precision(30);
	cout << (double)ans; 
	
	return 0;
}