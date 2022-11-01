#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (a % b) return gcd(b, a % b);
	return b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> cnt(200001);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 1; j * j <= a[i]; j++) {
			if (a[i] % j) continue;
			cnt[j]++;
			if (j * j != a[i]) cnt[a[i] / j]++;
		}
	vector <ll> d;
	for (int i = 2; i < 200001; i++)
		if (cnt[i] + 1 >= n) 
			d.push_back(i);
	ll ans = 1;
	for (int i = 0; i < d.size(); i++) 
		ans = ans * d[i] / gcd(ans, d[i]);
	cout << ans;
	return 0;
}