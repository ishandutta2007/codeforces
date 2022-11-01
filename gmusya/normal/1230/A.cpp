#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> a;

int main() {
	n = 4;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	if (a[0] + a[3] == a[1] + a[2] || (a[3] == a[1] + a[2] + a[0])) cout << "YES";
	else cout << "NO";
	return 0;
}