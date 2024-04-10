#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool is_balanced(const string& s) {
	int bal = 0;
	for (char c : s) {
		bal += (c == '(' ? 1 : -1);
		if (bal < 0) {
			return false;
		}
	}
	return bal == 0;
}

void solve() {
	int n = 2 * nxt();
	string s;
	cin >> s;
	vector<int> p(n + 1);
	for (int i = 0; i < n; ++i) {
		p[i + 1] = p[i] + (s[i] == '(' ? 1 : -1);
	}
	if (*min_element(all(p)) == 0) {
		cout << "0\n";
		return;
	}
	int left_len = 0, right_len = 0;
	while (p[left_len + 1] >= 0) {
		++left_len;
	}
	while (p[n - right_len - 1] >= 0) {
		++right_len;
	}
	int l = *max_element(p.begin(), p.begin() + left_len + 1);
	int r = *max_element(p.end() - right_len - 1, p.end());
	int mn = *min_element(p.begin() + left_len, p.end() - right_len);
	int mx = *max_element(p.begin() + left_len, p.end() - right_len);
	assert(l + r - mn >= 0);
	if (l + r - mx >= 0) {
		cout << "1\n";
		cout << max_element(p.begin(), p.begin() + left_len + 1) - p.begin() + 1 << " " << max_element(p.end() - right_len - 1, p.end()) - p.begin() << "\n";
	} else {
		int pos = max_element(p.begin() + left_len, p.end() - right_len) - p.begin();
		cout << "2\n";
		cout << max_element(p.begin(), p.begin() + left_len + 1) - p.begin() + 1 << " " << pos << "\n";
		cout << pos + 1 << " " << max_element(p.end() - right_len - 1, p.end()) - p.begin() << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}