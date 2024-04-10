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
		int temp = n;
		string ans;
		for (int i = 0; i < temp; ++i) {
			if (n > 0) {
				ans += '8';
				n -= 4;
			} else {
			 ans += '9';
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
}