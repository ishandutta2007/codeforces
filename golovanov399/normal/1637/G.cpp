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

ostream& operator <<(ostream& ostr, const vector<int>& a) {
	ostr << "[";
	for (int i = 0; i < (int)a.size(); ++i) {
		ostr << (i ? ", " : "") << a[i];
	}
	return ostr << "]";
}

void solve() {
	int n = nxt();
	if (n == 2) {
		cout << "-1\n";
		return;
	}
	vector<pair<int, int>> answer;
	vector<int> rem;
	function<void(int, int)> rec = [&](int cnt, int step) {
		if (cnt == 0) {
			return;
		}
		if (cnt == 1) {
			rem.push_back(step);
			return;
		}
		int p2 = 1;
		while (p2 < cnt) {
			p2 *= 2;
		}
		if (cnt == p2) {
			rem.push_back(cnt * step);
			--cnt;
		}
		int c = p2 / 2;
		p2 *= step;
		int pr = c - 1;
		int cn = 0;
		for (int i = 1; i < c && c + i <= cnt; ++i) {
			--pr;
			++cn;
			rem.push_back(p2);
			answer.push_back({(c - i) * step, (c + i) * step});
		}
		rem.push_back(c * step);
		rec(pr, step);
		rec(cn, step * 2);
	};
	rec(n, 1);
	int p2 = 1;
	while (p2 < n) {
		p2 *= 2;
	}
	sort(all(rem));
	if (rem[0]) {
		int i = 0;
		while (rem[i] != rem[i + 1]) {
			++i;
		}
		answer.push_back({rem[i], rem[i + 1]});
		rem[i + 1] *= 2;
		rem[i] = 0;
		sort(all(rem));
	}
	while (rem.back()) {
		int x = rem.back();
		while (x < p2) {
			answer.push_back({0, x});
			answer.push_back({x, x});
			x *= 2;
		}
		rem.pop_back();
	}
	while (!rem.empty()) {
		answer.push_back({0, p2});
		rem.pop_back();
	}
	cout << answer.size() << "\n";
	for (auto [x, y] : answer) {
		cout << x << " " << y << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}