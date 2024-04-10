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

void solve() {
	int n = nxt(), x = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	if (*min_element(all(a)) == *max_element(all(a)) && x % *min_element(all(a)) == 0 && x <= accumulate(all(a), 0)) {
		cout << "NO\n";
		return;
	}
	if (x == accumulate(all(a), 0)) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	int i = 0;
	int s = 0;
	while (i < n && s + a[i] <= x) {
		s += a[i++];
	}
	if (i < n && s == x) {
		if (a[i] == a[i - 1]) {
			int j = i + 1;
			while (j < n && a[j] == a[i]) {
				++j;
			}
			if (j < n) {
				swap(a[i], a[j]);
			} else {
				j = i - 1;
				while (j >= 0 && a[j] == a[i]) {
					--j;
				}
				assert(j >= 0);
				swap(a[j], a[i - 1]);
			}
		}
		swap(a[i], a[i - 1]);
	}
	for (int x : a) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}