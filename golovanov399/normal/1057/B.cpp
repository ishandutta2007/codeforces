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
		a[i] = nxt() - 100;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int s = 0;
		for (int j = i; j < n; ++j) {
			s += a[j];
			if (s > 0) {
				ans = max(ans, j - i + 1);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}