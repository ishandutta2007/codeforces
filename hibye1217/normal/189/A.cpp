#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
#define fr first
#define sc second
using pi2 = pair<int, int>;

int dp[4020];

void Main(){
	int n, a, b, c; cin >> n >> a >> b >> c;
	memset(dp, -1, sizeof(dp)); dp[0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j : {a, b, c}){
			if (i < j || dp[i-j] == -1){ continue; }
			dp[i] = max(dp[i], dp[i-j] + 1);
		}
	}
	cout << dp[n];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}