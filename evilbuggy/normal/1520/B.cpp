#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		int ans = 0;
		for(int d = 1; d < 10; d++){
			long long cur = d;
			while(cur <= n){
				ans++;
				cur = cur*10 + d;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}