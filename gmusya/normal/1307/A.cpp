#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			while (d >= i && a[i] > 0) {
				cnt++;
				d -= i;
				a[i]--;
			}
		}
		cout << cnt + a[0] << endl;
	}
	return 0;
}