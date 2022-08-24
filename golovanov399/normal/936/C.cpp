#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool check(string s, string t, const vector<int>& ops, bool show_all = false) {
	int n = s.length();
	for (int x : ops) {
		if (show_all) {
			cerr << s << "\n";
		}
		string t = s.substr(n - x);
		reverse(all(t));
		s = t + s.substr(0, n - x);
	}
	if (show_all) {
		cerr << s << "\n";
	}
	if (s == t) {
		cerr << "ok\n";
	} else {
		cerr << "expected " << t << ", got " << s << "\n";
	}
	return s == t;
}

int main() {
	int n = nxt();
	string s, t;
	cin >> s >> t;
	vector<int> cnt(26, 0);
	for (char c : s) {
		cnt[c - 'a'] += 1;
	}
	for (char c : t) {
		cnt[c - 'a'] -= 1;
	}
	if (cnt != vector<int>(26, 0)) {
		cout << "-1\n";
		return 0;
	}

	auto init_s = s;

	vector<int> ans;

	function<void(int)> flip = [&](int len) {
		ans.push_back(n - len);
		// cerr << s << " --(" << n - len << ")->";
		reverse(s.begin(), s.begin() + len);
		reverse(all(s));
		// cerr << " " << s << "\n";
	};

	for (int l = 0, r = n - 1; l < r; ++l, --r) {
		int i = l, j = r;
		while (s[i] != t[l]) {
			++i;
		}
		while (s[j] != t[r]) {
			--j;
		}

		if (i < j) {
			flip(i + 1);
			flip(n - j);
			flip(i + 1 - l);
			flip(n - j - l);
			flip(i + 1);
			flip(n - j);
			// cerr << l << ", " << s << ", " << t << "\n";
		} else {
			int a[7];
			// cerr << l << ", " << i << ", " << j << " (" << s << ")\n";
			a[0] = l;
			a[1] = j - l;
			a[2] = 1;
			a[6] = l;
			a[5] = r - i;
			a[4] = 1;
			a[3] = n - a[0] - a[1] - a[2] - a[6] - a[5] - a[4];
			// for (int k = 0; k < 7; ++k) {
			// 	cerr << a[k] << " ";
			// }
			// cerr << "\n";

			flip(a[0]);
			flip(a[6]);
			flip(a[0] + a[1] + a[2] + a[3]);
			flip(a[6] + a[5] + a[4] + a[0] + a[1]);
			flip(a[0] + a[2] + a[3] + a[4] + a[5] + a[6]);
			flip(a[1] + a[2] + a[3] + a[6]);
		}
	}

	// check(init_s, t, ans, false);

	printf("%d\n", (int)ans.size());
	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}