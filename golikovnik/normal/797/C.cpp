#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	string s;
	cin >> s;
	int n = szof(s);
	vector<char> suf_min(n + 1);
	suf_min[n] = 'z';
	for (int i = n - 1; i >= 0; --i) {
		suf_min[i] = min(s[i], suf_min[i + 1]);
	}	
	stack<char> st;
	string res;
	for (int i = 0; i < n; ++i) {
		st.push(s[i]);
		while (!st.empty() && st.top() <= suf_min[i + 1]) {
			res.push_back(st.top());
			st.pop();
		}
	}
	cout << res;
	return 0;	
}