#include <algorithm>
#include <iostream>
using namespace std;
bool dp[30000] = {true};
int cnt[26];

void solve()
{
	int n, m, k; cin >> n >> m >> k;
	string s; cin >> s;
	for (int i = 0; i < 26; ++i)
		cnt[i] = 0;
	for (char c : s)
		++cnt[c - 'A'];
	int res = m * n;
	for (int i = 0; i < 26; ++i)
	{
		for (int i = 1; i < n; ++i)
			dp[i] = false;
		for (int j = 0; j < 26; ++j)
			if (i != j)
				for (int i = n - 1; i >= cnt[j]; --i)
					dp[i] |= dp[i - cnt[j]];
		for (int j = n - 1; j >= 0; --j)
			if (dp[j] && j + cnt[i] >= n)
			{
				if (j + cnt[i] > k - m)
					res = min(res, (n - j) * (m + j + cnt[i] - k));
				else 
				{
					cout << "0" << endl;
					return;
				}
			}
	}
	cout << res << endl;
}

int main()
{
	int t; cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
	return 0;
}