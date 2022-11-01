#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	vector <ll> val(3);
	cin >> val[0] >> val[1] >> val[2];
	vector <pair <ll, ll>> a(3);
	for (ll i = 0; i < 3; i++)
		a[i] = { val[i], i };
	vector <ll> p(3);
	sort(a.begin(), a.end());
	for (ll i = 0; i < 3; i++) 
		p[a[i].second] = i;
	cout << "First" << endl;
	ll query = a[2].first + a[2].first - a[1].first - a[0].first;
	cout << query << endl;
	ll heap;
	cin >> heap;
	if (heap == 0) return 0;
	heap--;
	if (p[heap] == 2) {
		a[2].first += query;
		query = a[2].first + a[2].first - a[1].first - a[0].first;
		cout << query << endl;
		cin >> heap;
		if (heap == 0) return 0;
		heap--;
	}
	if (p[heap] == 0) {
		query = a[2].first - a[1].first;
		cout << query << endl;
		cin >> heap;
		if (heap == 0) return 0;
		heap--;
	}
	if (p[heap] == 1) {
		query = a[2].first - a[0].first;
		cout << query << endl;
		cin >> heap;
		if (heap == 0) return 0;
		heap--;
	}
	return 0;
}