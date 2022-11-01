#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <ll> m(n);
	for (int i = 0; i < n; i++)
		cin >> m[i];
	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += m[i];
	sum += n;
	vector <ll> a(n + 1);
	for (int i = n - 1; i >= 0; i--)
		a[i] = max(a[i + 1] - 1, m[i] + 1);
	for (int i = 1; i < n; i++)
		a[i] = max(a[i], a[i - 1]);
	for (int i = 0; i < n; i++)
		sum -= a[i];
	cout << -sum << endl;
	return 0;
}