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
	vector <ll> b(100001);
	for (int i = 0; i < n; i++)
		b[a[i]] += a[i];
	vector <ll> dyn(100001);
	dyn[1] = b[1];
	dyn[2] = max(b[1], b[2]);
	for (ll i = 3; i <= 100000; i++)
		dyn[i] = max(dyn[i - 2] + b[i], dyn[i - 1]);
	cout << dyn[100000];
	return 0;
}