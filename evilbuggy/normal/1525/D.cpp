#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int a[N], b[N], c[N], dp[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int szb = 0;
	int szc = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i]){
			++szb;
			b[szb] = i;
		}else{
			++szc;
			c[szc]  = i;
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1; i <= szc; i++){
		dp[i][0] = 0;
		for(int j = 1; j <= szb; j++){
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(b[j] - c[i]));
		}
	}
	cout << dp[szc][szb] << '\n';

	return 0;
}