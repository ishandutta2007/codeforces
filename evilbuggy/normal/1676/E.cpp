#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		int q; cin >> q;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.rbegin(), a.rend());
		for(int i = 1; i < n; i++){
			a[i] += a[i - 1];
		}
		while(q--){
			int x; cin >> x;
			if(x > a.back()){
				cout << -1 << '\n';
				continue;
			}
			int ind = lower_bound(a.begin(), a.end(), x) - a.begin();
			cout << ind + 1 << '\n';
		}
	}

	return 0;
}