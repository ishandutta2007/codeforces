#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int max = a[0], idmax = 0;
	for (int i = 0; i < n; i++) if (a[i] > max) {
		max = a[i];
		idmax = i;
	}
	bool tf1 = true, tf2 = true;
	for (int i = 0; i < idmax; i++) if (a[i + 1] < a[i]) tf1 = false;
	for (int i = idmax; i < n - 1; i++) if (a[i + 1] > a[i]) tf2 = false;
	if (tf1 && tf2) cout << "YES";
	else cout << "NO";
	return 0;
}