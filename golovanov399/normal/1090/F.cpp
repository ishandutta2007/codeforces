#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int ask(int x, int y, int z) {
	cout << "? " << x + 1 << " " << y + 1 << " " << z + 1 << endl;
	return nxt();
}

int main() {
	int n = nxt();
	vector<array<int, 4>> a;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				if (i < j && j < k) {
					a.push_back({ask(i, j, k), i, j, k});
				}
			}
		}
	}
	sort(all(a));
	vector<int> ans(n);
	vector<int> p(5);
	iota(all(p), 0);

	int s13 = a[0][0];
	int s14 = a[1][0]; // = a[2][0]
	int s15 = a[4][0]; // = a[5][0]
	// int s24 = a[3][0] + a[6][0] - s15; // fuck overflow
	int s25 = a[7][0]; // = a[8][0]
	int s35 = a[9][0];
	vector<int> scores(5);
	scores[0] = (s13 + s15 - s35) / 2;
	scores[4] = (s35 + s15 - s13) / 2;
	scores[2] = (s13 + s35 - s15) / 2;
	scores[1] = s25 - scores[4];
	scores[3] = s14 - scores[0];

	do {
		bool ok = true;
		for (auto v : a) {
			if (min({scores[p[v[1]]], scores[p[v[2]]], scores[p[v[3]]]}) + max({scores[p[v[1]]], scores[p[v[2]]], scores[p[v[3]]]}) != v[0]) {
				ok = false;
			}
		}
		if (ok) {
			break;
		}
	} while (next_permutation(all(p)));
	vector<int> q(5);
	for (int i = 0; i < 5; ++i) {
		q[p[i]] = i;
	}
	p.swap(q);
	for (int i = 0; i < 5; ++i) {
		ans[p[i]] = scores[i];
	}

	for (int i = 5; i < n; ++i) {
		int l = 0, r = 4;
		int tmp = ask(p[l], p[r], i);
		if (tmp < ans[p[l]] + ans[p[r]]) {
			ans[i] = tmp - ans[p[r]];
			continue;
		}
		if (tmp > ans[p[l]] + ans[p[r]]) {
			ans[i] = tmp - ans[p[l]];
			continue;
		}
		if (ask(p[l], p[2], i) == ans[p[l]] + ans[p[2]]) {
			ans[i] = ask(p[3], p[4], i) - ans[p[4]];
		} else {
			ans[i] = ask(p[0], p[1], i) - ans[p[0]];
		}
	}

	cout << "!";
	for (int x : ans) {
		cout << " " << x;
	}
	cout << endl;

	return 0;
}