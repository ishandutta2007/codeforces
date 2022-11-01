#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long int n;
	cin >> n;
	vector <long long int> a(n);
	for (long long int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	long long int sum = 0;
	for (long long int i = 0; i < n; i++) sum += a[i];
	if (sum % 2 == 0 && a[n - 1] <= sum / 2) cout << "YES";
	else cout << "NO";
	return 0;
}