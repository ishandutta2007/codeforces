#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define ll long long int

using namespace std;

ll n;
vector <pair <ll, ll>> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	for (int i = 0; i < n; i++) {
		ll x = (a[i].second + a[i].first - 1) / a[i].first;
		ll x1 = a[i].second % a[i].first;
		ll x2 = a[i].first - x1;
		if (a[i].first >= a[i].second)
			cout << a[i].second << endl;
		else 
			cout << x2 * (a[i].second / a[i].first) * (a[i].second / a[i].first) + x1 * (a[i].second / a[i].first + 1) * (a[i].second / a[i].first + 1) << endl;
	}
	return 0;
}