#include "bits/stdc++.h"

using namespace std;

#define fori(i, a, b) for(int i = (int) (a); i <= (int) (b); ++i)
#define ford(i, a, b) for(int i = (int) (a); i >= (int) (b); --i)
#define forIT(it, begin, end) for(__typeof(end) it = (begin) + ((begin) > (end)); it != (end) - ((begin) > (end)); it += 1 - 2 * ((begin) > (end)))

#define fi first
#define se second
#define b_e(x) begin(x), end(x)
#define ii pair<int, int>
#define vi vector<int> 
#define vvi vector<vi>

#define pb push_back
#define pf push_front
#define eb emplace_back
#define em emplace
#define ob pop_back
#define om pop
#define of pop_front

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define sp ' '

void solve();

int32_t main() {
// freopen("test.inp","r",stdin);
// freopen("test.out","w",stdout);
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   int test_num = 1;
   cin >> test_num; 
   fori(test, 1, test_num) {
      solve();
   }
   return 0;
}

#define ld long double
#define int long long
const ld pi = 4 * atan(1.0), eps = 1e-9;
const int maxn = 100 + 5, inf = INT_MAX / 2ll, maxs = 1e4 + 5; 
int n; 
int a[maxn], b[maxn]; 
int dp[maxn][maxs]; 
void solve() {
	cin >> n; 
	fori(i, 1, n) cin >> a[i]; 
	fori(i, 1, n) cin >> b[i];
	fori(i, 1, n) a[i + n] = b[i];  
	int S0 = 0, S1 = 0; 
	fori(i, 1, n) S0 += a[i] * a[i], S0 += b[i] * b[i]; S0 *= (n - 1); 
	fori(i, 1, 2 * n) fori(j, i + 1, 2 * n) S1 += a[i] * a[j]; 
	// S0 + S1 -S2
	fori(i, 0, maxn - 1) fori(j, 0, maxs - 1) dp[i][j] = -inf; 
	dp[0][0] = 0; 
	int S2 = -inf; 
	fori(i, 1, n) { 
		fori(s, 0, maxs - 1) { 
			if(s >= a[i]) dp[i][s] = max(dp[i][s], dp[i - 1][s - a[i]] + b[i]); 
			if(s >= b[i]) dp[i][s] = max(dp[i][s], dp[i - 1][s - b[i]] + a[i]); 
			if(i == n and dp[i][s] != -inf) S2 = max(S2, s * dp[i][s]); 
		}
	}
	cout << S0 + 2 * (S1 - S2) << endl; 
}