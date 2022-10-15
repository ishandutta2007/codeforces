#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> ct(32);
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			int cur = 0;
			while (x) {
				ct[cur++] += x & 1;
				x >>= 1;
			}
		}     
		string ans = "DRAW";
		for (int i = 31; i >= 0; --i) {
			if (ct[i] & 1) {
				if (ct[i] % 4 == 3 && n & 1) {
					ans = "LOSE";
				} else ans = "WIN";
				break;
			}
		}
		cout << ans << '\n';
	}
}