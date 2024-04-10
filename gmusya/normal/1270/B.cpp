#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		bool tf = false;
		pair <ll, ll> answer;
		for (ll i = 0; i < n - 1; i++)
			if (abs(a[i] - a[i + 1]) > 1) {
				tf = true;
				answer.first = i;
				answer.second = i + 1;
			}
		if (tf) {
			cout << "YES" << endl;
			cout << answer.first + 1 << " " << answer.second + 1 << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}