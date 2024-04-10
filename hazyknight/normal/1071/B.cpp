#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

int n,k,MAX;
int f[2005][2005];

char c[2005][2005];

string s;

vector<pair<int,int> > cur,tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> s;
		for (int j = 1;j <= n;j++)
			c[i][j] = s[j - 1];
	}
	f[1][1] = (c[1][1] != 'a');
	for (int i = 2;i <= n;i++)
	{
		f[i][1] = f[i - 1][1] + (c[i][1] != 'a');
		f[1][i] = f[1][i - 1] + (c[1][i] != 'a');
	}
	for (int i = 2;i <= n;i++)
		for (int j = 2;j <= n;j++)
			f[i][j] = min(f[i - 1][j],f[i][j - 1]) + (c[i][j] != 'a');
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (f[i][j] == k)
				MAX = max(MAX,i + j - 1);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (f[i][j] == k && i + j - 1 == MAX)
				cur.push_back(make_pair(i,j));
	if (f[n][n] < k)
	{
		for (int i = 1;i <= 2 * n - 1;i++)
			cout << 'a';
		cout << endl;
		return 0;
	}
	if (k == 0)
	{
		MAX = 1;
		cur.push_back(make_pair(1,1));
		cout << c[1][1];
	}
	else
	{
		for (int i = 1;i <= MAX;i++)
			cout << 'a';
	}
	for (int i = MAX + 1;i < n + n;i++)
	{
		tmp.clear();
		char C = 'z';
		for (int j = 0;j < cur.size();j++)
		{
			if (cur[j].second < n)
				C = min(C,c[cur[j].first][cur[j].second + 1]);
			if (cur[j].first < n)
				C = min(C,c[cur[j].first + 1][cur[j].second]);
		}
		cout << C;
		for (int j = 0;j < cur.size();j++)
		{
			if (cur[j].second < n && c[cur[j].first][cur[j].second + 1] == C && (!tmp.size() || tmp.back().first != cur[j].first || tmp.back().second != cur[j].second + 1))
				tmp.push_back(make_pair(cur[j].first,cur[j].second + 1));
			if (cur[j].first < n && c[cur[j].first + 1][cur[j].second] == C)
				tmp.push_back(make_pair(cur[j].first + 1,cur[j].second));
		}
		cur.clear();
		for (int j = 0;j < tmp.size();j++)
			cur.push_back(tmp[j]);
	}
	cout << endl;
	return 0;
}