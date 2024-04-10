#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n * n);
	for (int i = 0; i < n * n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	vector<int> ans;
	multiset<int> todel;

	for (int i = a.size() - 1; i >= 0; --i) {
		bool chk = true;
		for (int k = 0; k < ans.size(); ++k) {
			if (ans[k] % a[i] == 0)
				chk = false;
		}

		if (chk) {
			//not divisors of what in ans
			for (int k = 0; k < ans.size(); ++k) {
				todel.insert(__gcd(ans[k], a[i]));
				todel.insert(__gcd(ans[k], a[i]));
			}
			ans.push_back(a[i]);
		} else {
			if (todel.find(a[i]) != todel.end())
				todel.erase(todel.find(a[i]));
			else {
				for (int k = 0; k < ans.size(); ++k) {
					todel.insert(__gcd(ans[k], a[i]));
					todel.insert(__gcd(ans[k], a[i]));
				}
				ans.push_back(a[i]);
			}
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}