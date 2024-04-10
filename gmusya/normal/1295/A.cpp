#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string ans;
		while (n % 2 != 0 && n > 0) {
			ans = "7" + ans;
			n -= 3;
		}
		while (n % 2 == 0 && n > 0) {
			ans = ans + "1";
			n -= 2;
		}
		cout << ans << endl;
	}
	return 0;
}