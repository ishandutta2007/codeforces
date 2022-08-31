#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	vector<string> st;
	for (int i = 0; i < n - 2; ++i) {
		string s;
		cin >> s;
		if (st.empty()) {
			st.emplace_back(1, s[0]);
		}
		if (st.back().back() == s[0]) {
			st.back() += s[1];
		} else {
			st.push_back(s);
		}
	}
	if ((int)st.size() == 1) {
		st.push_back("a");
	}
	cout << st[0] << st[1] << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}