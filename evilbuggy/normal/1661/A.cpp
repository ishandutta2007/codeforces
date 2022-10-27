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
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		long long ans = 0;
		for(int i = 1; i < n; i++){
			int aa = abs(a[i] - a[i - 1]);
			int ab = abs(a[i] - b[i - 1]);
			int ba = abs(b[i] - a[i - 1]);
			int bb = abs(b[i] - b[i - 1]);
			ans += min(aa + bb, ab + ba);
		}
		cout << ans << '\n';
	}

	return 0;
}