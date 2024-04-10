#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), [&](string a, string b) {
		return a + b < b + a;
	});
	for (int i = 0; i < n; i++) {
		cout << v[i];
	}
	cout << endl;
	return 0;
}