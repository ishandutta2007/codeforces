#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <int> ans(n, -1);
	for (int i = 1; i < n; i++)
		if (a[i] > a[i - 1])
			ans[i] = a[i - 1];
	if (a[0] == 1) ans[0] = 0;
	vector <int> cnt(n + 10);
	for (int i = 0; i < n; i++)
		cnt[a[i]]++;
	int it = 1;
	for (int i = 0; i < n; i++) {
		while (cnt[it]) it++;
		if (ans[i] != -1) continue;
		ans[i] = it++;
	}
	for (auto &now : ans)
		cout << now << ' ';
	return 0;
}