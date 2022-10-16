#include <bits/stdc++.h>

using namespace std;
/*input
3
2 1 3
*/
/*input
3
2 2 2
*/
/*input
4
1 2 3 4
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	deque<int> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	for (int i = 1; i < n; ++i) {
		if (i % 2) {
			a.pop_back();
		}
		else {
			a.pop_front();
		}
	}

	cout << a[0];
}