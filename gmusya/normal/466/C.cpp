#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long 

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <ll> sum(n);
	vector <ll> cn1(n), cn2(n);
	sum[0] = a[0];
	for (ll i = 1; i < n; i++)
		sum[i] = sum[i - 1] + a[i];
	if (sum[n - 1] % 3 != 0) {
		cout << "0";
		return 0;
	}
	ll cnt1 = 0;
	for (ll i = 0; i < n; i++) {
		if (sum[i] == sum[n - 1] / 3)
			cnt1++;
		cn1[i] = cnt1;
	}
	ll cnt2 = 0;
	for (ll i = n - 1; i >= 0; i--) {
		if (sum[n - 1] - sum[i] == sum[n - 1] / 3)
			cnt2++;
		cn2[i] = cnt2;
	}
	ll ans = 0;
	ans += cn1[0] * cn2[1];
	for (ll i = 1; i < n - 1; i++)
		ans += (cn1[i] - cn1[i - 1]) * cn2[i + 1];
	if (sum[n - 1] == 0)
		cout << (cnt1 - 2) * (cnt1 - 1) / 2;
	else
		cout << max((ll)0, ans);
	
	return 0;
}