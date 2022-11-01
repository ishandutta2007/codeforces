// July 16, 2018


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
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	int a = 0, b = n - 1;
	long long sa = 0, sb = 0;

	long long best = 0;
	while (a - 1 < b + 1) {
		if (sa < sb) {
			sa += d[a++];
		} else if (sa > sb) {
			sb += d[b--];
		} else {
			best = sa;
			sa += d[a++];
			sb += d[b--];
		}
	}
	cout << best << '\n';


	return 0;
}