#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <char> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <int> r(26, -1), l(26, -1);
	for (int i = n - 1; i >= 0; i--)
		if (r[a[i] - 'A'] == -1)
			r[a[i] - 'A'] = i;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (l[a[i] - 'A'] == -1)
			l[a[i] - 'A'] = i;
	bool tf = false;
	for (int i = 0; i < n; i++) {
		if (i == l[a[i] - 'A'])
			cnt++;
		if (cnt > k)
			tf = true;
		if (i == r[a[i] - 'A'])
			cnt--;
	}
	if (tf)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}