#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		long long n; cin >> n;
		if(n%2050 == 0){
			n /= 2050;
			int ans = 0;
			while(n){
				ans += n%10;
				n /= 10;
			}
			cout << ans << '\n';
		}else{
			cout << -1 << '\n';
		}
	}

	return 0;
}