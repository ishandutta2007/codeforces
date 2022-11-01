#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n), b(n), pa(n), pb(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		pa[a[i] - 1] = i;
	for (int i = 0; i < n; i++)
		pb[b[i] - 1] = i;
	vector <int> dis(n);
	for (int i = 0; i < n; i++) {
		int d = pa[i] - pb[i];
		if (d < 0) d += n;
		dis[d]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dis[i]);
	cout << ans;
	return 0;
}