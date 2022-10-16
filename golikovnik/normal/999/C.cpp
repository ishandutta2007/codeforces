#include <bits/stdc++.h>

// #define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> used(n, 1);
	for (char c = 'a'; c <= 'z'; ++c) {
		for (int i = 0; i < n; ++i) {
			if (k and used[i] and s[i] == c) {
				used[i] = 0;
				--k;
			}
		}
	}	
	for (int i = 0; i < n; ++i) {
		if (used[i]) cout << s[i];
	}
	cout << "\n";
	return 0;
}