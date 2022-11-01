#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	vector <ll> a(4);
	for (ll i = 0; i < 4; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	cout << a[3] - a[2] << " " << a[3] - a[1] << " " << a[3] - a[0];
	return 0;
}