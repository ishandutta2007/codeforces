#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define ll long long 

using namespace std;

int main() {
	ll p, y;
	cin >> p >> y;
	bool tf;
	for (ll i = y; i > p; i--) {
		tf = true;
		for (ll j = 2; j <= min(p, (ll)ceil(sqrt(i)) + 1); j++) 
			if (i % j == 0) 
				tf = false;
		if (tf) {
			cout << i;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}