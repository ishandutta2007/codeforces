#include <bits/stdc++.h>

using namespace std;

int n;

char s[15][5005];

vector<pair<int,int> > ans;

int main()
{
	cin >> n;
	int L = 6 * n + 10,H = 10;
	for (int i = 1;i <= L;i++)
		s[H][i] = s[1][i] = '#';
	for (int i = 1;i <= H;i++)
		s[i][1] = s[i][L] = '#';
	if (n & 1)
	{
		n--;
		s[H][L + 1] = s[H][L + 2] = s[H + 1][L] = s[H + 1][L + 2] = s[H + 2][L] = s[H + 2][L + 1] = s[H + 2][L + 2] = '#';
	}
	for (int i = 1;i <= n / 2;i++)
	{
		int x = H,y = i * 6 - 1;
		for (int j = -2;j <= 2;j++)
			s[x + j][y - 2] = s[x + j][y + 2] = s[x - 2][y + j] = s[x + 2][y + j] = '#';
	}
	for (int i = 1;i <= H + 2;i++)
		for (int j = 1;j <= L + 2;j++)
			if (s[i][j] == '#')
				ans.push_back(make_pair(i,j));
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}