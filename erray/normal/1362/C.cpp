#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		long long n;
		cin >> n;
		long long ans = 0;
		for (long long i = 1; i <= n; i<<=1) {
			ans += n/i;
		}
		cout << ans << '\n';
	}
}