#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		int m; cin >> m;
		vector<string> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ans = 26*m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				int val = 0;
				for(int k = 0; k < m; k++){
					int c = a[i][k] - 'a';
					int d = a[j][k] - 'a';
					val += abs(c - d);
				}
				ans = min(ans, val);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}