#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

int n;
int cnt[4][3];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		if (s[s.size() - 1] == 'S')
			cnt[s.size() - 1][0]++;
		if (s[s.size() - 1] == 'M')
			cnt[s.size() - 1][1]++;
		if (s[s.size() - 1] == 'L')
			cnt[s.size() - 1][2]++;
	}
	for (int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		if (s[s.size() - 1] == 'S')
			cnt[s.size() - 1][0]--;
		if (s[s.size() - 1] == 'M')
			cnt[s.size() - 1][1]--;
		if (s[s.size() - 1] == 'L')
			cnt[s.size() - 1][2]--;
	}
	int ans = 0;
	for (int i = 0;i <= 3;i++)
		for (int j = 0;j < 3;j++)
			if (cnt[i][j] > 0)
				ans += cnt[i][j];
	cout << ans << endl;
	return 0;
}