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
const int MAXN = 1111;

int n, m;
int a[MAXN];
int dp[MAXN][MAXN][2];

int main() {
	
	cin >> n >> m;
	
	if (n > m) {
		cout << "YES\n";
		return 0;
	}

	forn(i, n) {
		cin >> a[i];
		a[i] %= m;
	}
	
	dp[0][0][0] = 1;
	forn(i, n) {
		forn(k, 2) {
			forn(j, m)
				dp[i + 1][j][k] |= dp[i][j][k];
			forn(j, m)
				dp[i + 1][(j + a[i]) % m][1] |= dp[i][j][k];	
		}
	}
	
	cout << (dp[n][0][1] ? "YES" : "NO");		
	
	return 0;
}