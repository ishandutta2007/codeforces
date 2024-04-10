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

int solve(vector<int> a) {
	int n = a.size();
	if (n == 1) {
		return 1;
	}
	int ans = n;
	for (int i = 1; i < n; ++i) {
		int x = a[i];
		if (x != a[i - 1]) {
			continue;
		}
		int j = i;
		while (j + 1 < n && a[j] == x && a[j + 1] != x) {
			j += 2;
		}
		if (j + 1 < n && a[j] == x && a[j + 1] == x) {
			--ans;
		}
	}
	return ans;
}

int stupid(vector<int> a) {
	int n = a.size();
	int ans = 1;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] != a[i + 1]) {
			++ans;
		}
	}
	for (int mask = 1; mask < (1 << n) - 1; ++mask) {
		int l0 = -1, l1 = -1;
		int tmp = 0;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				tmp += l1 != a[i];
				l1 = a[i];
			} else {
				tmp += l0 != a[i];
				l0 = a[i];
			}
		}
		ans = max(ans, tmp);
	}
	return ans;
}

int main() {
	// for (int n = 1; n <= 6; ++n) {
	// 	vector<int> a(n);
	// 	while (a[0] < n) {
	// 		int st = stupid(a);
	// 		int so = solve(a);
	// 		if (st != so) {
	// 			cout << n << "\n";
	// 			for (int x : a) {
	// 				cout << x + 1 << " ";
	// 			}
	// 			cout << "\nstupid: " << st << "\n solve: " << so << "\n";
	// 			return 0;
	// 		} else {
	// 			// cerr << "ok ";
	// 		}

	// 		a.back() += 1;
	// 		for (int i = n - 1; i > 0; --i) {
	// 			if (a[i] == n) {
	// 				a[i] = 0;
	// 				a[i - 1] += 1;
	// 			} else {
	// 				break;
	// 			}
	// 		}
	// 	}
	// }
	// while (true) {
	// 	const int n = 12;
	// 	vector<int> a(n);
	// 	for (int i = 0; i < n; ++i) {
	// 		a[i] = rand() % n;
	// 	}
	// 	int st = stupid(a);
	// 	int so = solve(a);
	// 	if (st != so) {
	// 		cout << n << "\n";
	// 		for (int x : a) {
	// 			cout << x + 1 << " ";
	// 		}
	// 		cout << "\nstupid: " << st << "\n solve: " << so << "\n";
	// 		return 0;
	// 	} else {
	// 		cerr << "ok ";
	// 	}
	// }

	int n = nxt();
	vector<int> a(n);
	for (int& x : a) {
		x = nxt() - 1;
	}
	cout << solve(a) << "\n";

	return 0;
}