// October 28, 2018
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	int N;
	cin >> N;
	vector<int> a(N + 1);
	a[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	vector<int> ans;
	for (int k = 1; k <= N; k++) {
		vector<int> x(k);
		for (int i = 0; i < k; i++) {
			x[i] = a[i + 1] - a[i];
		}
		bool works = true;
		for (int i = 1; i <= N; i++) {
			if (a[i] != x[(i - 1) % k] + a[i - 1]) {
				works = false;
			}
		}
		if (works) {
			ans.push_back(k);
		}
	}
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
	cout << '\n';


	return 0;
}