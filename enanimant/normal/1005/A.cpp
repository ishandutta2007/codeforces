#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	int n;
	cin >> n;

	vector<int> ans;
	int a = -1, b;
	while (n--) {
		cin >> b;
		if (b == 1 && a != -1) {
			ans.push_back(a);
		}
		a = b;
	}
	ans.push_back(a);

	cout << ans.size() << '\n';
	for (int i : ans) {
		cout << i << ' ';
	}
	cout << '\n';


	return 0;
}