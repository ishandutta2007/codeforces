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
const int LEN = 21;
const int MAXN = 3333;

int n, sz;
int a[MAXN], sa[MAXN];
ll dp[MAXN][MAXN];
ll ans, cur;
    
int main() {
	
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &a[i]);
		a[i] -= i;	
	}
	
	forn(i, n)
		sa[i] = a[i];
	sort(sa, sa + n);
	sz = unique(sa, sa + n) - sa;
	
	for (int i = 0; i < sz; i++)
		dp[0][i] = abs(a[0] - sa[i]);
	for (int i = 1; i < n; i++) {
		ll curMin = 1E18;	
		for (int j = 0; j < sz; j++) {
			curMin = min(curMin, dp[i - 1][j]);
			dp[i][j] = curMin + abs(a[i] - sa[j]);	
		}
	}
	
	ans = 1E18;
	forn(i, sz)
		ans = min(ans, dp[n - 1][i]);
	cout << ans << '\n';
	
	return 0;
}