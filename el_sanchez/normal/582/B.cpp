//#define _GLIBCXX_DEBUG
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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9; 
const int MAXN = 111;
         
int n, t;
int a[MAXN][MAXN], tmp[MAXN][MAXN];
int arr[MAXN], dp[MAXN], v[MAXN];
int dp2[MAXN];

int main() {
	
	cin >> n >> t;
	forn(i, n)
		cin >> arr[i];

	forn(i, n)
		dp[i] = 1;

	for (int L = 0; L < n; L++) {
		int bound = arr[L];

		forn(i, n)
			dp2[i] = 0;
			
		for (int R = 0; R < n; R++) {
			if (arr[R] >= bound) {
				dp2[R] = 1;
				for (int i = 0; i < R; i++)
					if (bound <= arr[i] && arr[i] <= arr[R])
						dp2[R] = max(dp2[R], dp2[i] + 1);	
			}
			
			a[L][R] = dp2[R];
		}
	}

	forn(i, n)
		forn(j, n)
			dp[i] = max(dp[i], a[j][i]);
			       
	//multiply
	t--;
	while (t > 0) {
		if (t & 1) {
			forn(i, n) {
				v[i] = 0;
				forn(k, n)
					if (dp[k] > 0 && a[k][i] > 0)
						v[i] = max(v[i], dp[k] + a[k][i]);				
			}
				
			forn(i, n)
				dp[i] = v[i];
		}
		
		t >>= 1;
		
		forn(i, n)
			forn(j, n) {
				tmp[i][j] = 0;
				forn(k, n)
					if (a[i][k] > 0 && a[k][j] > 0)
						tmp[i][j] = max(tmp[i][j], a[i][k] + a[k][j]);				
			}
			
		forn(i, n)
			forn(j, n)
				a[i][j] = tmp[i][j];
	}
	
	int ans = 0;
	forn(i, n)
		ans = max(ans, dp[i]);
	cout << ans;
	
	return 0;
}