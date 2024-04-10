/*input
1802

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<string> names{"Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };

	for (int i = 0; true; i++) {
		for (int j = 0; j < 5; j++) {
			n -= (1ll << i);
			//cout << n << endl;

			if (n <= 0) {
				cout << names[j];
				return 0;
			}
		}
	}



	return 0;
}