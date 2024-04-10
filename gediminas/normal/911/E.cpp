/*input
5 2
3 4
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	bool eg[n] = {};

	for (int i = 0; i < k; i++) {
		cin >> a[i];
		a[i]--;
		eg[a[i]] = true;
	}

	stack<int> s;

	int kit = 0;

	for (int i = 0; i < k; i++) {
		if (!s.empty() and s.top() < a[i]) {
			cout << "-1";
			return 0;
		}

		s.push(a[i]);

		while (!s.empty() and s.top() == kit) {
			s.pop();
			kit++;
		}
	}

	int po = k;
	int ma = -1;

	while (po != n) {
		int nuo = n - 1;

		if (!s.empty())
			nuo = s.top();

		for (int j = nuo; j > ma; j--) {
			if (!eg[j])
				a[po++] = j;
		}

		ma = nuo;

		if (!s.empty())
			s.pop();
	}

	for (int i = 0; i < n; i++)
		cout << a[i] + 1 << " ";

	return 0;
}