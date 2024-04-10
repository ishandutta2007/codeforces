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
	cin >> x;
	return x;
}

pair<int, int> ask(vector<int> a) {
	cout << "?";
	for (int x : a) {
		cout << " " << x + 1;
	}
	cout << endl;
	int pos = nxt() - 1, val = nxt();
	return {pos, val};
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), k = nxt();
	vector<int> a(k);
	iota(all(a), 0);
	auto [pos, val] = ask(a);

	vector<int> bigger, smaller;
	for (int i = k; i < n; ++i) {
		a[pos] = i;
		if (ask(a).second > val) {
			bigger.push_back(i);
		} else {
			smaller.push_back(i);
		}
	}
	int x = -1;
	bool is_bg = false;
	if (bigger.empty()) {
		x = smaller[0];
	} else {
		x = bigger[0];
		is_bg = true;
	}
	a[pos] = pos;

	int m = 1;
	for (int i = 0; i < k; ++i) {
		if (i == pos) {
			continue;
		}
		a[i] = x;
		int v = ask(a).second;
		if ((v == val) == (!is_bg)) {
			++m;
		}
		a[i] = i;
	}
	cout << "! " << m << endl;

	return 0;
}