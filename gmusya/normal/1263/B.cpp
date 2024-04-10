#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <string> codes(n);
		for (int i = 0; i < n; i++)
			cin >> codes[i];
		vector <bool> used(10);
		for (int i = 0; i < n; i++)
			used[codes[i][3] - '0'] = true;
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (codes[i] == codes[j]) {
					ans++;
					int x = 0;
					while (used[x])
						x++;
					used[x] = true;
					codes[i][3] = x + '0';
				}
		cout << ans << endl;
		for (int i = 0; i < n; i++)
			cout << codes[i] << endl;
	}
	return 0;
}