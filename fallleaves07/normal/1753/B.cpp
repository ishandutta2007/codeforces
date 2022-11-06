#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n, x;
	cin >> n >> x;
	vector<int> cnt(x);
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		if (d < x) {
			++cnt[d];
		}
	}
	bool tag = true;
	for (int i = 1; i < x; i++) {
		if (i + 1 < x) {
			cnt[i + 1] += cnt[i] / (i + 1);
		}
		cnt[i] %= i + 1;
		if (cnt[i]) {
			tag = false;
		}
	}
	puts(tag ? "Yes" : "No");
    return 0;
}