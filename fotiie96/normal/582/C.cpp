#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = int(2e5) + 10;

const int MAX_VALUE = int(1e6) + 10;

int n, a[MAX_N];

vector<int> divs_gcd[1000];
vector<int> divs;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i < n; ++i) {
		if (n % i == 0)
			divs.push_back(i);
	}

	for (int i = 1; i < n; ++i) {
		int g = __gcd(n, i);
		int at = lower_bound(divs.begin(), divs.end(), g) - divs.begin();
		divs_gcd[at].push_back(i);
	}

	long long ans = 0;

	for (int it = 0; it < divs.size(); ++it) {
		int s = divs[it];
		static int md[MAX_N];
		memset(md, -1, sizeof md);

		vector<int>&v = divs_gcd[it];

		for (int i = 0; i < n; ++i) {
			md[i % s] = max(md[i % s], a[i]);
		}

		int cur = 0;
		for (int i = 0; i < n * 2; ++i) {
			if (md[i % s] == a[i % n]) {
				++cur;
			} else {
				cur = 0;
			}
			if (i >= n) {
				//n...n+n-1
				ans += upper_bound(v.begin(), v.end(), cur) - v.begin();
			}
		}
	}

	cout << ans << endl;
}