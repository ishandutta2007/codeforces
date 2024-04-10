#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<int, int> mp;
		long long ans = 0;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			ans += mp[x - i];
			mp[x - i]++;
		}
		cout << ans << '\n';
	}

	return 0;
}