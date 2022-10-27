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
		int sum = 0, mn = INT_MAX;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
			mn = min(mn, a[i]);
		}
		cout << sum - mn*n << '\n';
	}

	return 0;
}