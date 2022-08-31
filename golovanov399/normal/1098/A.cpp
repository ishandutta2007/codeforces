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
	vector<int> p(n, -1);
	for (int i = 1; i < n; ++i) {
		p[i] = nxt() - 1;
	}
	vector<long long> s(n, 0), a(n);
	for (int i = 0; i < n; ++i) {
		s[i] = nxt();
		if (i == 0) {
			a[i] = s[i];
		} else if (s[i] != -1) {
			s[p[i]] = min(s[p[i]], s[i]);
		} else {
			s[i] = LLONG_MAX;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == LLONG_MAX) {
			s[i] = s[p[i]];
		}
	}
	for (int i = 1; i < n; ++i) {
		if (s[i] < s[p[i]]) {
			puts("-1");
			return 0;
		}
		a[i] = s[i] - s[p[i]];
	}
	cout << accumulate(all(a), 0ll) << "\n";

	return 0;
}