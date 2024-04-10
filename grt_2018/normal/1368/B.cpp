#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long k;
	cin >> k;
	for(int i = 10; ; ++i) {
		int mid = i / 10, rest = i - mid * 10;
		long long cnt = 1;
		for(int j = 0; j < 10 - rest; ++j) {
			cnt *= mid;
		}
		for(int j = 0; j < rest; ++j) {
			cnt *= (mid+1);
		}
		if(cnt >= k) {
			int x = 0;
			string ans = "";
			for(auto s : {'c','o','d','e','f','o','r','c','e','s'}) {
				if(x < 10 - rest) {
					for(int k1 = 0; k1 < mid; ++k1) {
						ans += s;
					}
				} else {
					for(int k1 = 0; k1 < mid+1; ++k1) {
						ans += s;
					}
				}
				x++;
			}
			cout << ans;
			return 0;
		}
	}
}