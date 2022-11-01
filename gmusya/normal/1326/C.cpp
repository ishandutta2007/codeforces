#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const ll MOD = 998244353;

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	k = n - k;
	vector <int> b(n);
	for (int i = 0; i < n; i++)
		if (a[i] > k) b[i] = 1;
	ll sum = 0;
	for (int i = n; i > k; i--)
		sum += i;
	vector <int> kek;
	for (int i = 0; i < n; i++)
		if (b[i] == 1) kek.push_back(i);
	ll ans = 1;
	for (int i = 0; i < kek.size() - 1; i++)
		ans = ans * (kek[i + 1] - kek[i]) % MOD;
	cout << sum << " " << ans;
	return 0;
}