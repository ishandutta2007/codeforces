#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <string> s = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
	vector <pair <int, int>> d(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 7; j++)
			if (s[i][j] == '1')
				d[i].first += (1 << j), d[i].second++;
	int n, k;
	cin >> n >> k;
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 7; j++)
			if (tmp[j] == '1')
				a[i].first += (1 << j), a[i].second++;
	}
	reverse(a.begin(), a.end());
	vector <vector <vector <bool>>> dp(n + 1, vector <vector <bool>>(k + 1, vector <bool>(10)));
	for (int i = 0; i < 10; i++) dp[0][0][i] = true;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++) {
			bool tf = false;
			for (int z = 0; z < 10; z++)
				if (dp[i - 1][j][z])
					tf = true;
			if (!tf) continue;
			for (int z = 0; z < 10; z++) 
				if ((a[i - 1].first | d[z].first) == d[z].first && j + (d[z].second - a[i - 1].second) <= k)
					dp[i][j + (d[z].second - a[i - 1].second)][z] = true;
		}
	vector <int> ans;
	while (n) {
		for (int i = 9; i >= 0; i--) {
			if (dp[n][k][i]) {
				ans.push_back(i);
				k -= d[i].second - a[n - 1].second;
				n--;
				break;
			}
			if (!i) {
				cout << -1;
				return 0;
			}
		}
	}
	for (auto &now : ans)
		cout << now;
	return 0;
}