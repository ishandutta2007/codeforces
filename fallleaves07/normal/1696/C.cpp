#include<bits/stdc++.h>
using namespace std;
using LL = long long;

bool solve() {
	vector<pair<int, LL>> a, b;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int val, cnt = 1;
		cin >> val;
		while (val % m == 0) {
			val /= m, cnt *= m;
		}
		if (!a.empty() && a.back().first == val) {
			a.back().second += cnt;
		} else {
			a.emplace_back(val, cnt);
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int val, cnt = 1;
		cin >> val;
		while (val % m == 0) {
			val /= m, cnt *= m;
		}
		if (!b.empty() && b.back().first == val) {
			b.back().second += cnt;
		} else {
			b.emplace_back(val, cnt);
		}
	}
	if (a.size() != b.size()) {
		return false;
	}
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		puts(solve() ? "Yes" : "No");
	}
    return 0;
}