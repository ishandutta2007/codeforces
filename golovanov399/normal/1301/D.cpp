#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

vector<pair<string, int>> ans;

void add(string s, int x) {
	if (!s.empty() && x > 0) {
		ans.push_back({s, x});
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = nxt(), m = nxt(), k = nxt();
	if (k > 2 * n * (m - 1) + 2 * (n - 1) * m) {
		puts("NO");
		return 0;
	}
	cout << "YES\n";

	add("D", n - 1);
	for (int i = n; i > 1; --i) {
		add("RUD", m - 1);
		add("L", m - 1);
		add("U", 1);
	}
	add("R", m - 1);
	add("L", m - 1);
	int i = 0;
	while (i < (int)ans.size() && k >= (int)ans[i].first.length() * ans[i].second) {
		k -= (int)ans[i].first.length() * ans[i].second;
		++i;
	}
	if (k) {
		ans[i].second = k / (int)ans[i].first.length();
		ans.resize(i + 1);
		if (k % (int)ans[i].first.length()) {
			string s = ans[i].first;
			add(s.substr(0, k % s.length()), 1);
			++i;
		}
	} else {
		--i;
	}
	ans.resize(i + 1);
	for (int i = 0; i < (int)ans.size(); ++i) {
		if (ans[i].second == 0) {
			ans.erase(ans.begin() + i);
			--i;
		}
	}
	cout << ans.size() << "\n";
	for (auto [s, c] : ans) {
		cout << c << " " << s << "\n";
	}

	return 0;
}