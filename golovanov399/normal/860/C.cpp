#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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
	cin >> x;
	return x;
}

struct Test {
	string name;
	bool sample;
};

int isNum(const string& s, int n) {
	int x = 0;
	if (s[0] == '0') {
		return 0;
	}
	for (char c : s) {
		if (c >= '0' && c <= '9') {
			x = x * 10 + c - '0';
		} else {
			return 0;
		}
		if (x > n) {
			return 0;
		}
	}
	if (x >= 1 && x <= n) {
		return x;
	} else {
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);

	int n = nxt();
	vector<int> is_sample(n, -1);
	vector<int> num(n);
	int sample_count = 0;
	vector<Test> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].name >> a[i].sample;
		int x = num[i] = isNum(a[i].name, n);
		if (x) {
			is_sample[x - 1] = a[i].sample;
		}
		if (a[i].sample) {
			sample_count += 1;
		}
	}

	int counts[2][2] = {{0, 0}, {0, 0}};
	// initial, needed

	vector<int> missed;
	vector<int> dmissed[2];
	for (int i = 0; i < n; ++i) {
		if (!num[i]) {
			missed.push_back(i);
			continue;
		}
		int x = (num[i] - 1 < sample_count);
		int y = a[i].sample;
		counts[x][y] += 1;
		if (x != y) {
			dmissed[x].push_back(i);
		}
	}

	vector<int> free_spaces[2];
	for (int i = 0; i < n; ++i) {
		if (is_sample[i] == -1) {
			free_spaces[i < sample_count].push_back(i);
		}
	}

	vector<pair<string, string>> ans;

	if (missed.empty()) {
		assert(counts[0][1] == counts[1][0]);
		if (!dmissed[0].empty()) {
			ans.push_back({a[dmissed[0][0]].name, "tmp"});
			for (int i = 0; i < (int)dmissed[0].size() - 1; ++i) {
				ans.push_back({a[dmissed[1][i]].name, a[dmissed[0][i]].name});
				ans.push_back({a[dmissed[0][i + 1]].name, a[dmissed[1][i]].name});
			}
			ans.push_back({a[dmissed[1].back()].name, a[dmissed[0].back()].name});
			ans.push_back({"tmp", a[dmissed[1].back()].name});
		}
	} else {
		while (!dmissed[0].empty() || !dmissed[1].empty()) {
			int index = (dmissed[0].size() && free_spaces[1].size() ? 0 : 1);
			assert(!dmissed[index].empty());
			ans.push_back({a[dmissed[index].back()].name, to_string(free_spaces[index ^ 1].back() + 1)});
			free_spaces[index].push_back(num[dmissed[index].back()] - 1);
			dmissed[index].pop_back();
			free_spaces[index ^ 1].pop_back();
		}
		for (int x : missed) {
			ans.push_back({a[x].name, to_string(free_spaces[a[x].sample].back() + 1)});
			free_spaces[a[x].sample].pop_back();
		}
	}

	cout << ans.size() << "\n";
	for (auto p : ans) {
		cout << "move " << p.first << " " << p.second << "\n";
	}

	return 0;
}