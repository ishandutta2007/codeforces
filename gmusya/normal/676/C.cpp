#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <char> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	vector <int> a;
	int cnt = 1;
	for (int i = 0; i < n - 1; i++) {
		if (c[i] != c[i + 1]) {
			a.push_back(cnt);
			cnt = 0;
		}
		cnt++;
	}
	a.push_back(cnt);
	vector <int> syma(a.size()), symb(a.size());
	for (int i = 0; i < a.size(); i += 2)
		syma[i] = a[i];
	for (int i = 1; i < a.size(); i += 2)
		symb[i] = a[i];
	vector <int> prefixa(a.size()), prefixb(a.size());
	prefixa[0] = syma[0];
	for (int i = 1; i < a.size(); i++)
		prefixa[i] = prefixa[i - 1] + syma[i];
	prefixb[0] = symb[0];
	for (int i = 1; i < a.size(); i++)
		prefixb[i] = prefixb[i - 1] + symb[i];
	int l = 0, r = 0, ans = 0;
	while (r < a.size()) {
		while (prefixa[r] - prefixa[l] > k)
			l += 2;
		ans = max(ans, prefixb[min(r + 1, (int) a.size() - 1)] - prefixb[l] + k);
		r += 2;
	}
	if (a.size() == 1) {
		cout << n;
		return 0;
	}
	if (a.size() == 2) {
		cout << min(max(a[0], a[1]) + k, n);
		return 0;
	};
	for (int i = 0; i < a.size(); i++)
		swap(prefixa[i], prefixb[i]);
	l = 0, r = 1;
	while (r < a.size()) {
		while (prefixa[r] - prefixa[l] > k)
			l += 2;
		if (l - 1 >= 0)
			ans = max(ans, prefixb[min(r + 1, (int) a.size() - 1)] - prefixb[l - 1] + k);
		else
			ans = max(ans, prefixb[min(r + 1, (int) a.size() - 1)] + k);
		r += 2;
	}
	cout << min(ans, n);
	return 0;
}