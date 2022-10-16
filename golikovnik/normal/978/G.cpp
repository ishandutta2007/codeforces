#include <bits/stdc++.h>

//#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int cmp_t;

struct Exam {
	int s, d, i;

	bool operator<(const Exam &other) const {
		if (cmp_t == 0) return s < other.s;
		return d < other.d;
	}
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> left(m);
	vector<int> have(n + 1);
	fill(have.begin(), have.end(), -1);	
	vector<Exam> a(m);
	for (int i = 0; i < m; ++i) {
		int s, d, c;
		cin >> s >> d >> c;
		a[i] = {s, d, i};
		left[i] = c;
		have[d] = i;
	}
	sort(a.begin(), a.end());
	cmp_t = 1;
	set<Exam> todo;
	bool ok = 1;
	vector<int> ans(n + 1);
	int ptr = 0;
	for (int day = 1; day <= n; ++day) {
		while (ptr < m and a[ptr].s <= day) {
			todo.insert(a[ptr]);
			++ptr;
		}
		if (have[day] >= 0) {
			ok &= !left[have[day]];
			ans[day] = m + 1;
		} else if (todo.empty()) {
			ans[day] = 0;
		} else {
			auto cur = todo.begin();
			ans[day] = cur->i + 1;
			--left[cur->i];
			if (!left[cur->i]) todo.erase(cur);
		}
	}
	ok &= todo.empty();
	if (ok) {
		for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
		cout << "\n";
	} else cout << -1;
	return 0;	
}