#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

using ll = long long;

int t = 0;
vector<pair<int, int>> Left;
vector<pair<int, int>> Right;

struct Trie {

	int sz;
	int root = 0;
	int last = 1;

	explicit Trie(int n) {
		sz = n;
	}

	void Add(int x) {
		int v = root;
		for (int pow = sz; pow >= 1; pow /= 2) {
			if (x & pow) {
				if (Left[v].first != t) {
					Left[v] = {t, last++};
				}
				v = Left[v].second;
			} else {
				if (Right[v].first != t) {
					Right[v] = {t, last++};
				}
				v = Right[v].second;
			}
		}
	}

	int Get(int x) {
		int ans = 0;
		int v = 0;
		for (int pow = sz; pow >= 1; pow /= 2) {
			if (x & pow) {
				if (Left[v].first == t) {
					v = Left[v].second;
				} else {
					ans += pow;
					v = Right[v].second;
				}
			} else {
				if (Right[v].first == t) {
					v = Right[v].second;
				} else {
					ans += pow;
					v = Left[v].second;
				}
			}
		}
		return ans;
	}
};

ll Solve(const vector<int>& arr, ll pow) {
	if (arr.size() <= 1 || pow == 0) {
		return 0;
	}
	vector<int> a, b;
	for (int x : arr) {
		if (x & pow) {
			a.push_back(x);
		} else {
			b.push_back(x);
		}
	}
	ll ans = Solve(a, pow / 2) + Solve(b, pow / 2);
	int res = 0;
	if (!a.empty() && !b.empty()) {
		++t;
		Trie trie(pow);
		for (int x: a) {
			trie.Add(x);
		}
		res = trie.Get(b[0]);
		for (int x: b) {
			res = min(res, trie.Get(x));
		}
	}
	return ans + res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	Left.resize(30 * n + 1);
	Right.resize(30 * n + 1);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cout << Solve(arr, 1 << 30);
	return 0;
}

/*
5
1 2 3 4 5
8
 */

/*
4
1 2 3 4
8
 */