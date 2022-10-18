/*input
1000000
*/
#include <bits/stdc++.h>

using namespace std;

int main () {

	bool sudet[1000005] = {};

	for (int i = 2; i < 1000005; i++) {
		if (!sudet[i]) {
			for (int j = 2 * i; j < 1000005; j += i){
				sudet[j] = true;
			}
		}
	}

	int n;
	cin >> n;

	for (int i = 2; i < n; i++) {
		if (sudet[i] and sudet[n - i]) {
			cout << i << " " << n - i << endl;
			return 0;
		}
	}

	return 1;
}