#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(const char *s = "NO"){cout << s;exit(0);} 
constexpr int maxn = 240000;
int a[maxn], s[maxn], f[maxn], dp[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1, j, p; i <= m; i += 1){
		cin >> j >> p;
		f[j] = max(f[j], p);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= k; i += 1) dp[i] = s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= k; i += 1){
		dp[i] = min(dp[i], dp[i - 1] + a[i]);
		for(int j = 1; j <= i; j += 1) if(f[j]){
			dp[i] = min(dp[i], dp[i - j] + s[i] - s[i - j + f[j]]);
		}
	}
	cout << dp[k];
}