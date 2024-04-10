#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <int> pr, lp(MAXN + 1);
	for (int i = 2; i <= MAXN; i++) {
		if (!lp[i]) pr.push_back(i), lp[i] = i;
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAXN; j++)
			lp[i * pr[j]] = pr[j];
	}
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <int> ans0(n, -1), ans1(n, -1);
	for (int i = 0; i < n; i++) {
		int x = a[i];
		vector <int> div;
		while (x != 1) {
			if (div.empty() || div.back() != lp[x]) div.push_back(lp[x]);
			x /= lp[x];
		}
		if (div.size() < 2) continue;
		ans0[i] = div[0];
		ans1[i] = 1;
		for (int j = 1; j < div.size(); j++)
			ans1[i] *= div[j];
	}
	for (int i = 0; i < n; i++)
		cout << ans0[i] << ' ';
	cout << '\n';
	for (int i = 0; i < n; i++)
		cout << ans1[i] << ' ';
	return 0;
}