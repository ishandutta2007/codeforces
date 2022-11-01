#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector <int> sum(n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int m;
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		cout << (sum[r] - sum[l - 1]) / 10 << endl;
	}
	return 0;
}