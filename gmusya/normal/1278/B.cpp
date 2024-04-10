#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b, x;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		ll cnt = 0;
		while (a < b || (a - b) % 2 != 0) {
			cnt++;
			a += cnt;
		}
		cout << cnt << endl;
	}
	return 0;
}