#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>


using namespace std;


int inf = 1e9;
int big_inf = 1e18;


int main() {
	int n, m;
	cin >> n >> m;
	vector < string > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	string sh;
	for (int i = 0; i < m + 2; ++i) {
		sh += '0';
	}

	pair <int, int> dp[15];
	pair <int, int> lol[15];

	for (int i = 0; i < n; ++i) {
		int j = n - i - 1;
		vector <int> lul;
		for (int k = 0; k < m + 2; ++k) {
			if (a[j][k] == '1') {
				lul.push_back(k);
			}
		}

		if (lul.size() >= 1) {
			lol[i].first = lul[0];
			lol[i].second = lul[lul.size() - 1];
		}
	}

	dp[0].second = m + 1;
	if (a[n - 1] == sh) {
		dp[0].first = 0;
	}
	else {
		dp[0].first = lol[0].second * 2;
	}

	for (int i = 1; i < n; ++i) {
		int j = n - i - 1;


		if (a[j] == sh) {
			dp[i].first = dp[i - 1].first + 1;
			dp[i].second = dp[i - 1].second + 1;
		}
		else {
			dp[i].first = min(dp[i - 1].second + m + 2, dp[i - 1].first + 1 + lol[i].second * 2);
			dp[i].second = min(dp[i - 1].first + m + 2, dp[i - 1].second + 1 + (m + 1 - lol[i].first) * 2);
		}
	}

	int up = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] != sh) {
			up = n - i - 1;
			break;
		}
	}

	if (up == -1) {
		cout << 0;
	}
	else if (up == 0) {
		cout << lol[0].second;
	}
	else {
		cout << min((dp[up - 1].first + 1) + lol[up].second, (dp[up - 1].second + 1) + (m + 2) - lol[up].first - 1);
	}

	return 0;
}