#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector <int> dp(n, 1);
	vector <int> chardp(26);
	for (int i = 0; i < n; i++) {
		for (int j = s[i] - 'a' + 1; j < 26; j++)
			dp[i] = max(dp[i], chardp[j] + 1);
		chardp[s[i] - 'a'] = max(chardp[s[i] - 'a'], dp[i]);
	}
	int ans = 0;
	for (int i = 0; i < 26; i++)
		ans = max(chardp[i], ans);
	if (ans > 2) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << dp[i] % 2;
	cout << endl;
	return 0;
}