#include <bits/stdc++.h>
#define ll long long
#define maxn 5005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int dp[maxn][maxn];
int nx[26];
ll tot[maxn];
ll jc[maxn], bjc[maxn];
int n;
char inp[maxn];
ll c(int a, int b) {
	return jc[a] * bjc[b] % mod * bjc[a - b] % mod;
}
int main() {
	jc[0] = bjc[0] = 1;
	for (int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % mod, 
		bjc[i] = ksm(jc[i], mod - 2);
		
	scanf("%d", &n);
	scanf("%s", inp + 1);
	for (int i = 0; i < 26; i++) nx[i] = n + 1;
	for (int i = n + 1; i >= 1; i--) {
		if (i == n + 1) {
			dp[i][0] = 1;
			continue;
		}
		int pl = inp[i] - 'a', nk = nx[pl];
	//	cout << "??" << nk << endl;
		for (int s = 0; s <= n + 1 - i; s++)
			tot[s] -= dp[nk + 1][s];
		nx[pl] = i, nk = nx[pl];
		for (int s = 0; s <= n + 1 - i; s++)
			tot[s] += dp[nk + 1][s];
		//, cout << s << ' ' << tot[s] << endl;
		int cur = n + 2;
		if (i != 1) cur = nx[inp[i - 1] - 'a'] + 1;
		for (int s = 0; s <= n + 1 - i; s++)
			dp[i][s + 1] = (tot[s] - dp[cur][s]) % mod;
		dp[i][0] = 1;
	}
	ll ans = 0;
	for (int j = 1; j <= n; j++)
		ans += c(n - 1, j - 1) * dp[1][j] % mod, 
		ans %= mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}