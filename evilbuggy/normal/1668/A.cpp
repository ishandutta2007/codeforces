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
		if(n > m)swap(n, m);

		if(n == 1){
			if(m <= 2)cout << m - 1 << '\n';
			else cout << -1 << '\n';
			continue;
		}
		long long ans = 2*(n - 1);
		if((m - n)&1){
			ans += 2*(m - n) - 1;
		}else{
			ans += 2*(m - n);
		}
		cout << ans << '\n';
	}

	return 0;
}