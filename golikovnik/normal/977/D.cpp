#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int log3(int x) {
	int res = 0;
	while (x % 3 == 0) {
		++res;
		x /= 3;
	}
	return res;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n;
	cin >> n;
	vector<int> a(n);
	int start = -1;
	int lg = -1;
	for (int &x: a) {
		cin >> x;
	}
	sort(all(a));
	for (int i = 0; i < n; ++i) {
		int tmp = log3(a[i]);
		if (tmp > lg) {
			lg = tmp;
			start = i;
		} else if (tmp == lg) {
			if (a[i] < a[start]) start = i;
		}
	}
	vector<int> res;
	res.push_back(a[start]);
	int did = 1;
	int now = a[start];
	while (did < n) {
		if (binary_search(all(a), now * 2)) {
			now *= 2;
			res.push_back(now);
			++did;
			continue;
		}	
		now /= 3;
		res.push_back(now);
		++did;
	}
	for (int x: res) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}