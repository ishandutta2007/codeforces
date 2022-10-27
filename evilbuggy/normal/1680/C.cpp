#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		vector<int> z(n + 1);
		for(int i = 0; i < n; i++){
			z[i + 1] = z[i] + (s[i] == '0');
		}
		int ans = n - z[n];
		for(int i = 1; i <= n; i++){
			if(z[i] <= (n - i) - (z[n] - z[i])){
				ans = min(ans, (n - i) - (z[n] - z[i]));
				continue;
			}
			int l = 0, r = i - 1;
			while(l <= r){
				int m = (l + r)/2;
				int cnt0 = z[i] - z[m];
				int cnt1 = (n - i) - (z[n] - z[i]) + m - z[m];
				if(cnt0 == cnt1){
					ans = min(ans, cnt0);
					break;
				}else if(cnt0 > cnt1){
					l = m + 1;
				}else{
					r = m - 1;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}