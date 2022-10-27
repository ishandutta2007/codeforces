#include <bits/stdc++.h>
using namespace std;

const int maxn = 205;
int a[maxn][maxn], sum1[maxn << 1], sum2[maxn << 1];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		int m; cin >> m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		for(int d = 0; d <= n + m; d++){
			sum1[d] = sum2[d] = 0;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				sum1[i + j] += a[i][j];
				sum2[i + m + 1 - j] += a[i][j];
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				ans = max(ans, sum1[i + j] + sum2[i + m + 1 - j] - a[i][j]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}