#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <int> a(n), b(m), ans(n);
	vector <int> x(1e5 + 1);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (x[a[i]] == 0)
			cnt++;
		x[a[i]]++;
		ans[i] = cnt;
	}
	for (int i = 0; i < m; i++)
		cout << ans[b[i] - 1] << endl;
	return 0;
}