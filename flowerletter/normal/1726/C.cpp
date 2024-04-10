#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> d(2 * n + 1, 0);
		stack<int> st;
		st.push(2 * n);
		for(int i = 0; i < 2 * n; ++i) {
			if(s[i] == '(') {
				if(!st.empty()) {
					int x = st.top();
					++d[x];
				}
				st.push(i);
			}
			else {
				st.pop();
			}
		}
		int ans = n;
		for(int i = 0; i <= 2 * n; ++i)
			ans -= max(0, d[i] - 1);
		cout << ans << '\n';
	}
	return 0;
}