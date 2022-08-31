#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	if (n == 2) {
		cout << "-1\n";
		return 0;
	}
	int k = 1;
	while (k * k < n) {
		k += 1;
	}
	if (n == k * k - 2) {
		++k;
	}

	vector<string> a(k, string(k, 'o'));
	int cur = k * k;
	if (cur > n) {
		--cur;
		a[0][k - 1] = '.';
	}
	if (cur > n) {
		assert(cur - 1 > n);
		cur -= 2;
		a[0][k - 2] = a[1][k - 1] = '.';
	}
	if (k == 1 || cur - n <= 2 * (k - 2) + 1) {
		if ((cur - n) % 2) {
			cur -= 1;
			a[1][k - 2] = '.';
		}
		for (int i = k - 3; cur > n; --i) {
			cur -= 2;
			a[0][i] = a[k - 1 - i][k - 1] = '.';
		}
	} else {
		assert(n == (k - 1) * (k - 1) - 2);
		for (int i = 1; i < k; ++i) {
			a[0][i] = a[k - 1 - i][k - 1] = '.';
		}
		a[2][k - 2] = '.';
		a[1][k - 2] = '.';
		a[2][k - 3] = '.';
		a[1][k - 3] = '.';
	}

	cout << k << "\n";
	for (auto s : a) {
		cout << s << "\n";
	}
	// cout << "\n";

	return 0;
}