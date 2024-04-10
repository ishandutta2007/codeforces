#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			int x; cin >> x; a[x - 1]++;
		}
		int ans = -1;
		for(int i = 0; i < n; i++){
			if(a[i] >= 3)ans = i + 1;
		}
		cout << ans << '\n';
	}

	return 0;
}