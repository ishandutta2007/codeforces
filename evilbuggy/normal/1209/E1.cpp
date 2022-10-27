#include <bits/stdc++.h>
using namespace std;

int a[12][2000], mx[2000], ord[2000];

inline void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		mx[i] = 0;
		ord[i] = i;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			mx[j] = max(mx[j], a[i][j]);
		}
	}
	sort(ord, ord + m, [&](int i, int j){
		return mx[i] > mx[j];
	});
	vector<int> dp(1 << n);
	for(int j = 0; j < n && j < m; j++){
		for(int mask = 0; mask < (1 << n); mask++){
			for(int i = 0; i < n; i++){
				if(((mask >> i) & 1) == 0){
					dp[mask^(1 << i)] = max(dp[mask^(1 << i)], dp[mask] + a[i][ord[j]]);
				}
			}
		}
		for(int mask = 0; mask < (1 << n); mask++){
			int curmask = mask, maxi = 0;
			for(int i = 0; i < n; i++){
				maxi = max(maxi, dp[curmask]);
				curmask = curmask << 1;
				if((curmask >> n) & 1){
					curmask ^= (1 << n)|1;
				}
			}
			curmask = mask;
			for(int i = 0; i < n; i++){
				dp[curmask] = maxi;
				curmask = curmask << 1;
				if((curmask >> n) & 1){
					curmask ^= (1 << n)|1;
				}
			}
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}