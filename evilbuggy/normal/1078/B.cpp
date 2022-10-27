#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = N*N;

int f[N], dp[N][M];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	set<int> distinct;
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++){
		int x; cin >> x; f[x]++;
		distinct.insert(x);
	}
	if(distinct.size() <= 2){
		cout << n << '\n';
		exit(0);
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i < N; i++){
		if(!f[i])continue;
		for(int c = N - 1; c >= 0; c--){
			for(int s = M - 1; s >= 0; s--){
				if(!dp[c][s])continue;
				for(int x = 1; x <= f[i]; x++){
					if(s + x*i > M)break;
					dp[c + x][s + x*i] += dp[c][s];
					if(dp[c + x][s + x*i] > 2){
						dp[c + x][s + x*i] = 2;
					}
				}
			}
		}
	}
	int ans = 1;
	for(int i = 1; i < N; i++){
		for(int x = 1; x <= f[i]; x++){
			if(dp[x][x*i] == 1)ans = max(ans, x);
		}
	}
	cout << ans << '\n';

	return 0;
}