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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 155;

int n, k, s;
int a[MAXN];
int ans;
int dp1[MAXN][MAXN * MAXN], dp2[MAXN][MAXN * MAXN];

int main() {

	cin >> n >> k >> s;
	s = min(s, n * n);
	forn(i, n)
		cin >> a[i];
		
	if (k == n) {
		ans = 0;
		forn(i, n)
			ans += a[i];
		cout << ans << '\n';
		return 0;
	}
	
	forn(i, MAXN)
		forn(j, MAXN * MAXN) {
			dp1[i][j] = -INF;
			dp2[i][j] = INF;
		}
		
	dp1[0][0] = 0;
	
	int maxSwaps = 0;
	int curSwaps;
	for (int i = k - 1; i >= 0; i--) {
		maxSwaps += (k - 1 - i + 1) * 2;
		maxSwaps = min(maxSwaps, s);
		maxSwaps = s;
		for (int taken = k - 1 - i; taken >= 0; taken--)
			for (int swaps = 0; swaps <= maxSwaps; swaps++)
				if (dp1[taken][swaps] != -INF) {
					curSwaps = (k - 1 - i + 1) + taken;
					if (swaps + curSwaps <= s)
						dp1[taken + 1][swaps + curSwaps] = max(dp1[taken + 1][swaps + curSwaps], dp1[taken][swaps] + a[i]);
				}
	}
	
	dp2[0][0] = 0;
	maxSwaps = 0;
	
	for (int i = k; i < n; i++) {
		maxSwaps += i - k + 1;
		maxSwaps = min(maxSwaps, s);
		maxSwaps = s;
		for (int taken = i - k; taken >= 0; taken--)
			for (int swaps = 0; swaps <= maxSwaps; swaps++)
				if (dp2[taken][swaps] != INF) {
					curSwaps = i - (k + taken);
					if (swaps + curSwaps <= s)
						dp2[taken + 1][swaps + curSwaps] = min(dp2[taken + 1][swaps + curSwaps], dp2[taken][swaps] + a[i]);
				}
	}
	
	int current = 0;
	forn(i, k)
		current += a[i];
	ans = current;	
	for (int take = min(k, n - k); take >= 0; take--) {
		for (int s1 = 1; s1 <= s; s1++)
			dp1[take][s1] = max(dp1[take][s1], dp1[take][s1 - 1]);
			
		int min2 = INF;
		for (int s1 = s; s1 >= 0; s1--) {
			min2 = min(min2, dp2[take][s - s1]);
			if (dp1[take][s1] != -INF && min2 != INF) {
				ans = min(ans, current - dp1[take][s1] + min2);
			}
			
			/*
			for (int s2 = 0; s2 <= s; s2++) {
				if (dp1[take][s1] != -INF && dp2[take][s2] != INF && s1 + s2 <= s) {
					ans = min(ans, current - dp1[take][s1] + dp2[take][s2]);
				}
			}*/		
		}
	}
	
	cout << ans;
	
	return 0;
}