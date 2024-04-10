//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int n;
int r[3];
ll we[2][maxn];
int a[maxn];
int d;
ll dp[maxn];
int main() {
	cin >> n >> r[0] >> r[1] >> r[2] >> d;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		we[0][i] = 1ll * r[0] * a[i] + r[2];
		we[1][i] = r[0] + r[1];
		chkmin(we[1][i], 1ll * r[0] * a[i] + 2 * r[0]);
		chkmin(we[1][i], we[0][i]);
	//	cout << we[0][i] << ' ' << we[1][i] << endl;
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + we[0][i];
		chkmin(dp[i], dp[max(0, i - 2)] + 2 * d + we[1][i] + we[1][i - 1]);
	}
	ll ans = dp[n];
	ll sum = we[0][n];
	for (int i = n - 1; i >= 1; i--) {
		sum += we[1][i];
		chkmin(ans, dp[i - 1] + sum + 1ll * (n - i) * d);
	}
	ans += 1ll * (n - 1) * d;
	cout << ans << endl;
	return 0;
}