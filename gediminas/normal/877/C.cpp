/*input
3

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a;

	for (int i = 2; i <= n; i += 2)
		a.push_back(i);

	for (int i = 1; i <= n; i += 2)
		a.push_back(i);

	for (int i = 2; i <= n; i += 2)
		a.push_back(i);

	cout << a.size() << "\n";

	for (auto && x : a)
		cout << x << " ";


	return 0;
}