#include<bits/stdc++.h> 
using namespace std;
constexpr int maxn = 20;
char s[maxn][maxn + 1];
int a[maxn][maxn];
int dp[1 << maxn];
bool vis[1 << maxn];
int n, m;
string bin(int x){
	string res;
	for(int nn = n; nn; x /= 2, nn -= 1) res.push_back(x % 2 + '0');
	return res;
}
int f(int mask){
	if(vis[mask]) return dp[mask];
	vis[mask] = true;
	dp[mask] = 1e9;
	int k = 0;
	while(not ((1 << k) & mask)) k += 1;
	for(int j = 0; j < m; j += 1){
		int ans = 0, d = 0, maxz = 0;
		for(int i = 0; i < n; i += 1) if(s[i][j] == s[k][j])
			ans += a[i][j], d |= 1 << i, maxz = max(maxz, a[i][j]);
		dp[mask] = min(dp[mask], f(mask & ~d) + ans - maxz);
		dp[mask] = min(dp[mask], f((1 << k) ^ mask) + a[k][j]);
	}
	return dp[mask];
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i += 1) cin >> s[i];
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1) cin >> a[i][j];
	vis[0] = true;
	cout << f((1 << n) - 1);
}