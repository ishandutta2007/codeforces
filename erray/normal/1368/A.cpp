#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		long long n, a, b;
		cin >> a >> b >> n;
		int ans = 0;
		while (a <= n && b <= n) {
		 	if (a > b) swap(a, b);
		 	a += b;
		 	++ans;
		}
		cout << ans << '\n';
	}
}