// July 13, 2018


#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	int n;
	cin >> n;
	vector<int> w(n), h(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> h[i];
	}

	int cur = max(w[0], h[0]);
	for (int i = 1; i < n; i++) {
		if (min(w[i], h[i]) > cur) {
			cout << "NO\n";
			return 0;
		}
		cur = (max(w[i], h[i]) > cur ? min(w[i], h[i]) : max(w[i], h[i]));
	}
	cout << "YES\n";


	return 0;
}