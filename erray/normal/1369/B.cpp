#include<bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		string s;
		cin >> n >> s;
		string ans;
		int ind = 0;
		while (ind < n && s[ind] == '0') {
			++ind;
		}		
		for (int i = ind; i < n; ++i) {
			if (s[i] == '0') {
				ans.clear();
			}
			ans += s[i];
		}
		cout << string(ind, '0') + ans << '\n';
	}
}