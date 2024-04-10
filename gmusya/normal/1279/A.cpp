#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long 

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		vector <ll> a(3);
		for (ll i = 0; i < 3; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		if (a[2] > a[1] + a[0] + 1)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}