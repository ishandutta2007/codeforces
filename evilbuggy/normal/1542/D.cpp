#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int mod = 998244353;

int a[N], dp[N][N];

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		char ch;
		cin >> ch;
		if(ch == '-')a[i] = 0;
		else cin >> a[i];
	}
	int answer = 0;
	for(int it = 1; it <= n; it++){
		if(a[it] == 0) continue;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		// Suppose x := a[it]
		// dp[p][q] = number of subsequences of operations from [1..p]
		// such that after applying these operations there are q elements
		// less than x and also
		// - If p < it: no additional constraints
		// - If p >= it: it should 
		for(int i = 1; i <= n; i++){
			// j - number of elements in the set < x after applying first i operations
			for(int j = 0; j <= i; j++){
				if(i == it){
					dp[i][j] = dp[i - 1][j];
				}else if(i < it){
					dp[i][j] = dp[i - 1][j];
					if(a[i] > 0){
						if(a[i] <= a[it]){
							if(j)add(dp[i][j], dp[i - 1][j - 1]);
						}else{
							add(dp[i][j], dp[i - 1][j]);
						}
					}else{
						add(dp[i][j], dp[i - 1][j + 1]);
						if(j == 0)add(dp[i][j], dp[i - 1][j]);
					}
				}else{
					dp[i][j] = dp[i - 1][j];
					if(a[i] > 0){
						if(a[i] < a[it]){
							if(j)add(dp[i][j], dp[i - 1][j - 1]);
						}else{
							add(dp[i][j], dp[i - 1][j]);
						}
					}else{
						add(dp[i][j], dp[i - 1][j + 1]);
					}
				}
			}
		}
		int total = 0;
		for(int j = 0; j <= n; j++){
			add(total, dp[n][j]);
		}
		add(answer, total*1LL*a[it]%mod);
	}
	cout << answer << '\n';

	return 0;
}