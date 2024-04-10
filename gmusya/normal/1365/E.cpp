#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector <ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a.push_back(0);
	a.push_back(0);
	n += 2;
	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				ans = max(ans, (a[i] | a[j] | a[k]));
	cout << ans;
	return 0;
}