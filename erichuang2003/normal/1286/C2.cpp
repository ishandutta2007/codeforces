#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 105;

int n,m,ST;
int u[MAXN];
int v[MAXN];
int cnt[26];

char a[MAXN];
char b[MAXN];
char ans[MAXN];

vector<string> S[MAXN];

void solve(int l,int r)
{
	if (l > r)
		return;
	int len = r - l + 1;
	cout << "? " << l << ' ' << r << endl;
	for (int i = 1;i <= len;i++)
		S[i].clear();
	for (int i = 1;i <= len * (len + 1) / 2;i++)
	{
		string s;
		cin >> s;
		S[s.size()].push_back(s);
	}
	for (int i = 1;i <= len / 2;i++)
	{
		memset(cnt,0,sizeof(cnt));
		for (int j = 0;j < S[i + 1].size();j++)
			for (int k = 0;k < S[i + 1][j].size();k++)
				cnt[S[i + 1][j][k] - 'a']++;
		for (int j = m;j >= m - i + 1;j--)
		{
			cnt[a[j] - 'a'] -= j - m + i - 1;
			cnt[b[j] - 'a'] -= j - m + i - 1;
		}
		for (int j = 0;j < S[1].size();j++)
			cnt[S[1][j][0] - 'a'] -= i + 1;
		m++;
		u[m] = l + i - 1;
		v[m] = r - i + 1;
		for (int j = 0;j < 26;j++)
		{
			if (cnt[j])
			{
				if (!a[m])
					a[m] = j + 'a';
				else
					b[m] = j + 'a';
				cnt[j]++;
			}
			if (cnt[j])
				b[m] = j + 'a';
		}
		for (int j = 0;j < S[1].size();j++)
			if (S[1][j][0] == a[m])
			{
				S[1].erase(S[1].begin() + j);
				break;
			}
		for (int j = 0;j < S[1].size();j++)
			if (S[1][j][0] == b[m])
			{
				S[1].erase(S[1].begin() + j);
				break;
			}
	}
	if (len & 1)
	{
		ST = l + r >> 1;
		ans[ST] = S[1][0][0];
	}
}

void dfs(int cur,int fa)
{
	for (int i = 1;i <= m;i++)
	{
		if (v[i] == cur)
			swap(u[i],v[i]);
		if (u[i] == cur && v[i] != fa)
		{
			if (ans[cur] == a[i])
				ans[v[i]] = b[i];
			else
				ans[v[i]] = a[i];
			dfs(v[i],u[i]);
		}
	}
}

int main()
{
	cin >> n;
	solve(1,n);
	if (n & 1)
	{
		solve(1,n / 2);
		solve(n / 2 + 1,n);
	}
	else
	{
		solve(1,n / 2 - 1);
		solve(n / 2 + 1,n);
	}
	dfs(ST,0);
	cout << "! ";
	for (int i = 1;i <= n;i++)
		cout << ans[i];
	cout << endl;
	return 0;
}