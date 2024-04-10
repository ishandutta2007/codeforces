// July 12, 2018


#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)

	int n, B;
	cin >> n >> B;
	vector<int> a(n);
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			even++;
		} else {
			odd++;
		}
	}
	if (even != odd) {
		cout << "0\n";
		return 0;
	}
	vector< pair<int, int> > cnt(n + 1);
	vector<int> costs;
	cnt[0] = {0, 0};
	for (int i = 0; i < n - 1; i++) {
		cnt[i + 1] = cnt[i];
		if (a[i] % 2 == 0) {
			cnt[i + 1].first++;
		} else {
			cnt[i + 1].second++;
		}
		if (cnt[i + 1].first == cnt[i + 1].second) {
			costs.push_back(abs(a[i + 1] - a[i]));
		}
	}
	sort(costs.begin(), costs.end());
	int ans = 0;
	for (int i : costs) {
		if (B - i < 0) break;
		B -= i;
		ans++;
	}

	cout << ans << '\n';


	return 0;
}