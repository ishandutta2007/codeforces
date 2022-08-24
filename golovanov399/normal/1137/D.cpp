#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

// #define TEST

#ifdef TEST
int g_t = 50, g_c = 41;
// int g_t = 1, g_c = 999;
int g_q = 3 * (g_t + g_c);

vector<string> get(vector<int> cur_idx) {
	for (int& x : cur_idx) {
		if (x >= g_t) {
			x = g_t + (x - g_t) % g_c;
		}
	}
	map<int, string> M;
	for (int i = 0; i < (int)cur_idx.size(); ++i) {
		M[cur_idx[i]] += (char)('0' + i);
	}
	vector<string> res;
	for (const auto& p : M) {
		res.push_back(p.second);
	}
	return res;
}
#endif

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = 10;
	vector<int> cur_idx(n);
	bool alt = true;
	while (true) {
		cout << "next";
#ifdef TEST
		--g_q;
		assert(g_q >= 0);
#endif
		vector<int> which = {0};
		cur_idx[0] += 1;
		if (alt) {
			which.push_back(1);
			cur_idx[1] += 1;
		}
		alt ^= 1;
		for (int x : which) {
			cout << " " << x;
		}
		cout << endl;

		vector<int> num(n);
#ifndef TEST
		int k = nxt();
		for (int i = 0; i < k; ++i) {
			string s;
			cin >> s;
#else
		auto p = get(cur_idx);
		for (auto s : p) cout << s << " ";
		cout << "\n";
		for (int i = 0; i < (int)p.size(); ++i) {
			auto s = p[i];
#endif
			for (char c : s) {
				num[c - '0'] = i;
			}
		}

		bool ok = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (cur_idx[i] != cur_idx[j] && num[i] == num[j]) {
					ok = true;
					break;
				}
			}
			if (ok) {
				break;
			}
		}
		if (ok) {
			break;
		}
	}

	while (true) {
		cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
		int k = nxt();
		for (int i = 0; i < k; ++i) {
			string s;
			cin >> s;
		}
		if (k == 1) {
			break;
		}
	}
	cout << "done" << endl;

	return 0;
}