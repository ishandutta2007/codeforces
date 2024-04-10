#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, p;
		cin >> n >> p;
		int cnt = 0;
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) {
				if (cnt == 2 * n + p)
					break;
				cout << i << " " << j << endl;
				cnt++;
			}
	}
	return 0;
}