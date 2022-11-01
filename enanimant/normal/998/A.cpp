// July 12, 2018


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
	vector<int> a(n);
	int min_ind = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[min_ind] > a[i]) {
			min_ind = i;
		}
	}

	if ((n == 1) || (n == 2 && a[0] == a[1])) {
		cout << "-1\n";
	} else {
		cout << "1\n" << min_ind + 1 << '\n';
	}


	return 0;
}