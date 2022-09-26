#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

int n,m,ANS;

char c[4];

string s[MAXN];
string t[MAXN];
string ans[MAXN];

void upd()
{
	int cnt = 0;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			cnt += (s[i][j] != t[i][j]);
	if (cnt < ANS)
	{
		ANS = cnt;
		for (int i = 0;i < n;i++)
			ans[i] = t[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> s[i];
		t[i] = s[i];
	}
	c[0] = 'A';
	c[1] = 'T';
	c[2] = 'G';
	c[3] = 'C';
	ANS = n * m + 1;
	do
	{
		for (int l = 0;l < 2;l++)
		{
			for (int i = 0;i < n;i++)
			{
				int dif[2] = {0,0};
				for (int j = 0;j < 2;j++)
					for (int k = 0;k < m;k++)
						if (c[(((i ^ l) & 1) << 1) | ((k ^ j) & 1)] != s[i][k])
							dif[j]++;
				int j = (dif[0] > dif[1]);
				for (int k = 0;k < m;k++)
					t[i][k] = c[(((i ^ l) & 1) << 1) | ((k ^ j) & 1)];
			}
		}
		upd();
		for (int l = 0;l < 2;l++)
		{
			for (int i = 0;i < m;i++)
			{
				int dif[2] = {0,0};
				for (int j = 0;j < 2;j++)
					for (int k = 0;k < n;k++)
						if (c[(((i ^ l) & 1) << 1) | ((k ^ j) & 1)] != s[k][i])
							dif[j]++;
				int j = (dif[0] > dif[1]);
				for (int k = 0;k < n;k++)
					t[k][i] = c[(((i ^ l) & 1) << 1) | ((k ^ j) & 1)];
			}
		}
		upd();
	}while (next_permutation(c,c + 4));
	for (int i = 0;i < n;i++,cout << endl)
		for (int j = 0;j < m;j++)
			cout << ans[i][j];
	return 0;
}