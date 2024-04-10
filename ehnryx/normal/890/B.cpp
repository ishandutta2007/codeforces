#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	unordered_set<int> seen;
	int last = -1;
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n-1; i >= 0; i--) {
		if (!seen.count(a[i])) {
			seen.insert(a[i]);
			last = a[i];
		}
	}
	cout << last << nl;

	return 0;
}