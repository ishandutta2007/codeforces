#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int n, R, C, s[1000100], r[1000100][22];
string a[1000100];
char str[5000100];

int main()
{
	cin >> n >> R >> C;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str);
		a[i] = string(str);
		s[i] = s[i - 1] + a[i].size();
	}
	
	for (int i = 1, j = 1; i <= n; i++)
	{
		while (j < n && s[j + 1] - s[i - 1] + j + 1 - i <= C) j++;
		if (s[j] - s[i - 1] + j - i <= C) r[i][0] = j;
		else r[i][0] = 0;
	}
	
	for (int j = 0; j < 20; j++)
		for (int i = 1; i <= n; i++)
			if (r[i][j] == n) r[i][j + 1] = n;
			else 
				if (!r[r[i][j] + 1][j]) r[i][j + 1] = r[i][j];
				else r[i][j + 1] = r[r[i][j] + 1][j];
	
	int ans = 0, rx = 0, ry = 0;
	for (int i = 1; i <= n; i++)
	{
		int curR = -1;
		for (int j = 20; j >= 0; j--)
			if (R >> j & 1)
			{
				if (curR < 0) curR = r[i][j];
				else curR = r[curR + 1][j];
				if (curR == n) break;
			}
		
		if (curR - i + 1 > ans) ans = curR - i + 1, rx = i, ry = curR;
	}
	
	if (ans)
		for (int i = rx; i <= ry; )
		{
			int j = i;
			while (j < ry && s[j + 1] - s[i - 1] + j + 1 - i <= C) j++;
			for (int k = i; k < j; k++) printf("%s ", a[k].c_str());
			puts(a[j].c_str());
			i = j + 1;
		}
}