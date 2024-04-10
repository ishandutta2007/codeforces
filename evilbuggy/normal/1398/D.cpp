#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 205;
ll dp[N][N][N], R[N], B[N], G[N];

void solve(){
	int r, g, b;
	cin>>r>>g>>b;
	for(int i = 1; i <= r; i++){
		cin>>R[i];
	}
	for(int i = 1; i <= g; i++){
		cin>>G[i];
	}
	for(int i = 1; i <= b; i++){
		cin>>B[i];
	}
	sort(R + 1, R + r + 1);
	sort(G + 1, G + g + 1);
	sort(B + 1, B + b + 1);
	memset(dp, 0, sizeof(dp));
	ll ans = 0;
	for(int i = 0; i <= r; i++){
		for(int j = 0; j <= g; j++){
			for(int k = 0; k <= b; k++){
				if(i && j)dp[i][j][k] = max(dp[i][j][k], R[i]*G[j] + dp[i - 1][j - 1][k]);
				if(k && j)dp[i][j][k] = max(dp[i][j][k], G[j]*B[k] + dp[i][j - 1][k - 1]);
				if(i && k)dp[i][j][k] = max(dp[i][j][k], R[i]*B[k] + dp[i - 1][j][k - 1]);
				ans = max(ans, dp[i][j][k]);
			}
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int t = 1;
	while(t--)solve();

	return 0;
}