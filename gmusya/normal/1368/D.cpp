#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <int> cnt(20);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 20; j++)
			if (a[i] & (1 << j)) 
				cnt[j]++;
	for (int i = 0; i < n; i++) {
		a[i] = 0;
		for (int j = 0; j < 20; j++)
			if (cnt[j]) {
				a[i] += (1 << j);
				cnt[j]--;
			}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long x = a[i];
		ans += x * x;
	}
	cout << ans;
	return 0;
}