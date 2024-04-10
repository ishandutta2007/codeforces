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
		int ans = 0;
		for(int i = n - 2; i >= 0; i--){
			while(a[i] != 0 && a[i] >= a[i + 1]){
				a[i] >>= 1; ans++;
			}
			if(a[i] >= a[i + 1]){
				ans = -1;
				break;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}