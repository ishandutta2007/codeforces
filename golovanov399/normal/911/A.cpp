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

	int m = *min_element(all(a));
	int lst = -1e9;
	int ans = 1e9;
	for (int i = 0; i < n; ++i) {
		if (a[i] == m) {
			ans = min(ans, i - lst);
			lst = i;
		}
	}

	cout << ans << "\n";
	
	return 0;
}