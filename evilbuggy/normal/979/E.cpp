#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int mod = 1000000007;

/*
1. index
2. number of zeroes
3. number of indices with zero with number of alternating paths ending with it equal to 0
4. number of indices with one  with number of alternating paths ending with it equal to 0
*/

int c[N], pw[N], dp[N][N][N][N];

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p;
	cin >> n >> p;
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	pw[0] = 1;
	for(int i = 1; i <= n; i++){
		pw[i] = pw[i - 1] << 1;
		if(pw[i] >= mod)pw[i] -= mod;
	}
	memset(dp, 0, sizeof(dp));

	dp[0][0][0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int z = 0; z <= i; z++){
			for(int p00 = 0; p00 <= z; p00++){
				for(int p10 = 0; p10 <= i - z; p10++){
					if(!dp[i][z][p00][p10])continue;
					int p01 = z - p00;
					int p11 = i - z - p10;
					if(c[i] != 0){
						if(p01){
							add(dp[i + 1][z][p00][p10 + 1], pw[i - 1]*1LL*dp[i][z][p00][p10]%mod);
							add(dp[i + 1][z][p00][p10], pw[i - 1]*1LL*dp[i][z][p00][p10]%mod);
						}else{
							add(dp[i + 1][z][p00][p10], pw[i]*1LL*dp[i][z][p00][p10]%mod);
						}
					}
					if(c[i] != 1){
						if(p11){
							add(dp[i + 1][z + 1][p00 + 1][p10], pw[i - 1]*1LL*dp[i][z][p00][p10]%mod);
							add(dp[i + 1][z + 1][p00][p10], pw[i - 1]*1LL*dp[i][z][p00][p10]%mod);
						}else{
							add(dp[i + 1][z + 1][p00][p10], pw[i]*1LL*dp[i][z][p00][p10]%mod);
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int z = 0; z <= n; z++){
		for(int p00 = 0; p00 <= z; p00++){
			for(int p10 = 0; p10 <= n - z; p10++){
				int p01 = z - p00;
				int p11 = n - z - p10;
				if((p01 + p11)%2 == p){
					add(ans, dp[n][z][p00][p10]);
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}