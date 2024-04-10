#include<bits/stdc++.h>
using namespace std;
using LL = long long;

bool solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	vector<LL> s(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	LL sum = a[k], l = k, r = k, sl = k, sr = k;
	while (l > 1 && r < n) {
		bool tag = false;
		while (l > 1 && s[sr] - s[l - 2] >= 0) {
			tag = true;
			--l;
			if (s[sr] - s[l - 1] >= sum) {
				sum = s[sr] - s[l - 1];
				sl = l;
			}
		}
		while (r < n && s[r + 1] - s[sl - 1] >= 0) {
			tag = true;
			++r;
			if (s[r] - s[sl - 1] >= sum) {
				sum = s[r] - s[sl - 1];
				sr = r;
			}
		}
		if (!tag) {
			break;
		}
	}
	return (l == 1 || r == n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		puts(solve() ? "YES" : "NO");
	}
    return 0;
}