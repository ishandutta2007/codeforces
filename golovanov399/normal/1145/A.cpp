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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	for (int len = n; len; len /= 2) {
		for (int start = 0; start < n; start += len) {
			if (is_sorted(a.begin() + start, a.begin() + start + len)) {
				cout << len << "\n";
				return 0;
			}
		}
	}

	return 0;
}