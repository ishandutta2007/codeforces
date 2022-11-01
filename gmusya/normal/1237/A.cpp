#include <iostream>
#include <vector>

#define ll long long 

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	ll cur_bal = 0;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++) 
		cur_bal += a[i] / 2;
	for (ll i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			if (cur_bal > 0 && a[i] < 0) {
				a[i]--;
				cur_bal--;
			}
			if (cur_bal < 0 && a[i] > 0) {
				a[i]++;
				cur_bal++;
			}
		}
		a[i] /= 2;
	}
	for (auto now : a)
		cout << now << endl;
	return 0;
}