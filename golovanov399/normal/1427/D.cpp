#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void perform(vector<int>& a, vector<int> c) {
	vector<int> res;
	reverse(all(c));
	for (int x : c) {
		res.insert(res.end(), a.end() - x, a.end());
		a.erase(a.end() - x, a.end());
	}
	assert(a.empty());
	a.swap(res);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<vector<int>> ans;
	while (true) {
		int x = 0, i = 0;
		while (x <= n) {
			++x;
			while (i < n && a[i] != x) {
				++i;
			}
			if (i == n) {
				break;
			}
		}
		if (x == n + 1) {
			break;
		}
		x -= 1;
		i = find(all(a), x) - a.begin();
		int j = find(all(a), x + 1) - a.begin();
		int cn = 1;
		while (a[j + cn] == a[j + cn - 1] + 1) {
			++cn;
		}
		ans.push_back({j, cn, i - j + 1 - cn, n - i - 1});
		// for (int x : a) {
		// 	cerr << x << " ";
		// }
		// cerr << "| ";
		// for (int x : ans.back()) {
		// 	if (x) {
		// 		cerr << x << " ";
		// 	}
		// }
		// cerr << "\n";
		perform(a, ans.back());
	}

	cout << ans.size() << "\n";
	for (auto& v : ans) {
		for (int i = 0; i < (int)v.size(); ++i) {
			while (i < (int)v.size() && v[i] == 0) {
				v.erase(v.begin() + i);
			}
		}
		cout << v.size();
		for (int x : v) {
			cout << " " << x;
		}
		cout << "\n";
	}

	return 0;
}