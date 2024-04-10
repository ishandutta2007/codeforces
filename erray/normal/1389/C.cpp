#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n = (int) s.size();	
		set<int> ct(s.begin(), s.end());                 	
		vector<int> lw(26);
		for (char c : s) ++lw[c - '0'];
	  int ans = n - *max_element(lw.begin(), lw.end());
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				int ind = 0, left = 0, temp = 0;
				while (left < n) {
					if (ind) {
						if (s[left] - '0' == i) {
							ind ^= 1;
						} else ++temp;
					}	else {
						if (s[left] - '0' == j) {
							ind ^= 1;
						} else ++temp;
					}
					++left;
				}
				ans = min(ans, temp + ((n - temp) & 1));		
			}
		}
		cout << ans << '\n';
	}
}