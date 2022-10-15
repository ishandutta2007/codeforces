#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	int sk = 0, hk = 0;
	for (int i = 0; i < n; i++) {
		string a, b; cin >> a >> b;
		if (b == "soft") {
			sk++;
		} else {
			hk++;
		}
	}
	for (int i = 1; ; i++) {
		int k1 = (i*i) / 2, k2 = (i*i+1) / 2;
		if ((sk <= k1 && hk <= k2) || (sk <= k2 && hk <= k1)) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}