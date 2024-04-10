#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[j] > a[i]) {
				ans ^= 1;
			}
		}
	}

	int m = nxt();
	while (m--) {
		int l = nxt(), r = nxt();
		l = (r - l + 1);
		l /= 2;
		if (l % 2) {
			ans ^= 1;
		}

		puts(ans ? "odd" : "even");
	}
	
	return 0;
}