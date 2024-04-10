#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
double dp[1 << 20], psum[1 << 20], p[20];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	bool flg = false;
	for(int i = 0; i < n; i++){
		cin >> p[i];
		if(abs(1.0 - p[i]) < EPS){
			flg = true;
		}
	}
	cout << fixed << setprecision(20);
	if(flg){
		for(int i = 0; i < n; i++){
			cout << p[i] << " ";
		}
		cout << '\n';
		exit(0);
	}
	dp[0] = 1.0;
	for(int mask = 1; mask + 1 < (1 << n); mask++){
		if(__builtin_popcount(mask) >= k)continue;
		
		dp[mask] = psum[mask] = 0.0;
		for(int i = 0; i < n; i++){
			if((mask >> i) & 1){
				dp[mask] += p[i]*dp[mask^(1 << i)];
				psum[mask] += p[i];
			}
		}
		if(abs(psum[mask] - 1.0) < EPS)dp[mask] = 1e18;
		else dp[mask] /= 1.0 - psum[mask];
	}
	for(int i = 0; i < n; i++){
		double answer = 0.0;
		for(int mask = 0; mask < (1 << n); mask++){
			if((mask >> i) & 1)continue;
			if(__builtin_popcount(mask) >= k)continue;
			
			answer += dp[mask];
		}
		answer *= p[i];
		cout << answer << " ";
	}
	cout << '\n';

	return 0;
}