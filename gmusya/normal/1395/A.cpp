#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int r, g, b, w;
		cin >> r >> g >> b >> w;
		if (r % 2 + g % 2 + b % 2 + w % 2 <= 1) {
			cout << "Yes\n";
			continue;
		}
		if (!r || !g || !b) {
			cout << "No\n";
			continue;
		}
		r--, g--, b--, w++;
		if (r % 2 + g % 2 + b % 2 + w % 2 <= 1)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}