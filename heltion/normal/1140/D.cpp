#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 600;
bool vis[maxn][maxn];
LL dp[maxn][maxn];
LL f(int i, int j){
	if(vis[i][j]) return dp[i][j];
	vis[i][j] = true;
	if(i + 1 == j) return 0;
	dp[i][j] = 1e18;
	for(int k = i + 1; k < j; k += 1)
		dp[i][j] = min(dp[i][j], f(i, k) + f(k, j) + 1LL * i * j * k);
	//cout << i << " " << j << " " << dp[i][j] << endl;
	return dp[i][j];
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << f(1, n);
}