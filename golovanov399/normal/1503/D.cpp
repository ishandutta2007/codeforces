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

void solve() {
	int n = nxt();
	vector<char> flipped(n);
	vector<int> id(2 * n);
	vector<int> other(2 * n);
	vector<pair<int, int>> card(n);

	bool fail = false;
	for (int i = 0; i < n; ++i) {
		int l = nxt() - 1, r = nxt() - 1;
		if (r < l) {
			flipped[i] = true;
			swap(l, r);
		}
		if (l >= n || r < n) {
			fail = true;
		}
		other[l] = r;
		other[r] = l;
		id[l] = id[r] = i;
		card[i] = {l, r};
	}
	if (fail) {
		cout << "-1\n";
		return;
	}

	auto covers = [](const pair<int, int>& fst, const pair<int, int>& snd) {
		return fst.first < snd.first && fst.second > snd.second;
	};
	vector<char> used(n);
	auto can_add = [&](vector<int>& ch, int id) {
		if (!ch.empty() && !covers(card[id], card[ch.back()])) {
			return false;
		}
		ch.push_back(id);
		used[id] = true;
		return true;
	};

	int ans = 0;
	int cur = 0;
	while (cur < n) {
		vector<int> chain[2];
		bool left = true;
		int from = n - 1 - cur, to = n - cur;
		int max_right = n + cur - 1, min_left = n - cur;
		while (from != to) {
			if (left) {
				swap(from, to);
				--from, --to;
			}
			int old_ml = min_left, old_mr = max_right;
			for (int i = from; i != to; left ? --i : ++i) {
				if (used[id[i]]) {
					continue;
				}
				if (!can_add(chain[left], id[i])) {
					cout << "-1\n";
					return;
				} else {
					min_left = min(min_left, left ? i : other[i]);
					max_right = max(max_right, left ? other[i] : i);
				}
			}
			if (left) {
				from = old_mr + 1;
				to = max_right + 1;
			} else {
				from = min_left;
				to = old_ml;
			}
			left ^= 1;
		}

		int sz = chain[0].size() + chain[1].size();
		cur += sz;
		int eq = 0;
		for (int i : chain[0]) {
			eq += flipped[i];
		}
		for (int i : chain[1]) {
			eq += !flipped[i];
		}
		ans += min(eq, sz - eq);
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}