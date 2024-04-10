#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ans = 0, sum = 0;
		for(int i = 0, j = n; i < j; i++){
			sum += a[i];
			while(i < j - 1 && sum - a[j - 1] >= 0){
				sum -= a[j - 1];
				j--;
			}
			if(sum == 0){
				ans = max(ans, i + 1 + n - j);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}