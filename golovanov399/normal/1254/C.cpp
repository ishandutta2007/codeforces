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

inline long long nxt() {
	long long x;
	cin >> x;
	return x;
}

long long ask(int t, int i, int j, int k) {
	cout << t << " " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
	return nxt();
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> left, right;
	for (int i = 2; i < n; ++i) {
		if (ask(2, 0, 1, i) > 0) {
			left.push_back(i);
		} else {
			right.push_back(i);
		}
	}

	vector<long long> S(n);
	for (int i = 2; i < n; ++i) {
		S[i] = ask(1, 0, 1, i);
	}
	vector<int> order(n);
	for (int x : left) {
		for (int y : left) {
			if (x == y) {
				break;
			}
			if (S[x] == S[y]) {
				order[x] = ask(2, 0, y, x);
				order[y] = -order[x];
			}
		}
	}
	for (int x : right) {
		for (int y : right) {
			if (x == y) {
				break;
			}
			if (S[x] == S[y]) {
				order[x] = ask(2, 0, y, x);
				order[y] = -order[x];
			}
		}
	}
	sort(all(left), [&](int i, int j) {
		return S[i] < S[j];
	});
	sort(all(right), [&](int i, int j) {
		return S[i] < S[j];
	});

	vector<int> left_beg, left_end;
	if (!left.empty()) {
		int idx = left.back();
		for (int i = 0; i < (int)left.size(); ++i) {
			if (order[left[i]]) {
				if (order[left[i]] < 0) {
					left_beg.push_back(left[i]);
				} else {
					left_end.push_back(left[i]);
				}
				++i;
				if (order[left[i]] < 0) {
					left_beg.push_back(left[i]);
				} else {
					left_end.push_back(left[i]);
				}
			} else if (left[i] == idx) {
				left_beg.push_back(idx);
			} else {
				if (ask(2, idx, 0, left[i]) > 0) {
					left_beg.push_back(left[i]);
				} else {
					left_end.push_back(left[i]);
				}
			}
		}
	}
	vector<int> right_beg, right_end;
	if (!right.empty()) {
		int idx = right.back();
		for (int i = 0; i < (int)right.size(); ++i) {
			if (order[right[i]]) {
				if (order[right[i]] < 0) {
					right_beg.push_back(right[i]);
				} else {
					right_end.push_back(right[i]);
				}
				++i;
				if (order[right[i]] < 0) {
					right_beg.push_back(right[i]);
				} else {
					right_end.push_back(right[i]);
				}
			} else if (right[i] == idx) {
				right_beg.push_back(idx);
			} else {
				if (ask(2, idx, 0, right[i]) > 0) {
					right_beg.push_back(right[i]);
				} else {
					right_end.push_back(right[i]);
				}
			}
		}
	}
	vector<int> ans = {0};
	reverse(all(left_end));
	reverse(all(right_end));
	ans.insert(ans.end(), all(right_beg));
	ans.insert(ans.end(), all(right_end));
	ans.push_back(1);
	ans.insert(ans.end(), all(left_beg));
	ans.insert(ans.end(), all(left_end));
	cout << 0;
	for (int x : ans) {
		cout << " " << x + 1;
	}
	cout << endl;

	return 0;
}