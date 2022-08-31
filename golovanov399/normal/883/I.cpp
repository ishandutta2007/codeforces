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

bool isOk(const vector<int>& a, int m, int k) {
	int n = (int)a.size();
	if (a.back() - a[n - k] > m) {
		return false;
	}
	vector<char> ok(n + 1);
	ok[n] = ok[n - k] = 1;
	int cnt = 1;
	int l = n - 1;
	int r = n - 1;

	for (int i = n - k - 1; i >= 0; --i) {
		while (a[r] - a[i] > m) {
			cnt -= ok[r + 1];
			--r;
		}
		cnt += ok[l];
		ok[i] = (cnt > 0);
		--l;
	}

	// cerr << m << ": ";
	// for (char c : ok) {
	// 	cerr << (char)('0' + c);
	// }
	// cerr << "\n";

	return ok[0];
}

int main() {
	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	sort(all(a));

	if (k == 1) {
		printf("0\n");
		return 0;
	}

	int l = -1, r = 1e9 + 10;

	while (r > l + 1) {
		int m = (l + r) / 2;
		if (isOk(a, m, k)) {
			r = m;
		} else {
			l = m;
		}
	}

	printf("%d\n", r);

	return 0;
}