#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n > m) {
		cout << 0;
		return 0;
	}
	vector <int> b;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			b.push_back(abs(a[i] - a[j]));
	for (int i = 0; i < b.size(); i++)
		b[i] = b[i] % m;
	int ans = 1;
	for (int i = 0; i < b.size(); i++)
		ans = (ans * b[i]) % m;
	cout << ans;
	return 0;
}