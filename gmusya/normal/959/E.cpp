#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> p(50), hm(50);
	p[0] = 1;
	for (ll i = 1; i < 50; i++)
		p[i] = p[i - 1] * 2;
	hm[0] = 0;
	for (ll i = 1; i < 50; i++)
		hm[i] = 2 * hm[i - 1] + p[i - 1];
	ll sum = 0;
	for (ll i = 0; i < 49; i++) {
		if ((p[i] & n) != 0) {
			sum += hm[i] + p[i];
		}
	}
	for (ll i = 0; i < 49; i++) {
		if ((p[i] & n) != 0) {
			sum -= p[i];
			break;
		}
	}
	cout << sum;
	return 0;
}