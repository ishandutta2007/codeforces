#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		if (n % 4) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vector <int> odd, even;
		for (int i = 0; i < n / 4; i++) {
			even.push_back(i * 6 + 2), even.push_back(i * 6 + 4);
			odd.push_back(i * 6 + 1), odd.push_back(i * 6 + 5);
		}
		for (int i = 0; i < n / 2; i++)
			cout << even[i] << ' ';
		for (int i = 0; i < n / 2; i++)
			cout << odd[i] << ' ';
		cout << '\n';
	}
	return 0;
}