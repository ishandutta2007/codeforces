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
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long sum = n + a[n - 1];
		for(int i = 1; i < n; i++){
			sum += a[i];
		}
		if(sum <= m){
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}
	}

	return 0;
}