#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;
 
const int MAXN = 105;
 
int n;
int a[MAXN];
int b[MAXN];
int ans[MAXN];
int as[MAXN];
 
int w[MAXN];
int c[MAXN];
 
pair<int,int> calc(int d)
{
	if (d)
		w[c[d]]++;
	int x = 0;
	for (int i = 1;i <= n;i++)
		x += w[i] * (w[i] - 1) * (w[i] - 2) / 6;
	int y = 0;
	for (int i = 1;i + 2 <= n;i++)
		y += w[i] * w[i + 1] * w[i + 2];
	return make_pair(x,y);
}
 
void dfs(int d)
{
	if (d > n)
	{
		memcpy(w,as,sizeof(w));
		pair<int,int> r = calc(0);
		if (r.first != a[0] || r.second != b[0])
			return;
		for (int i = 1;i <= n;i++)
		{
			r = calc(i);
			if (r.first != a[i] || r.second != b[i])
				return;
		}
		cout << "! ";
		for (int i = 1;i <= n;i++)
			cout << as[i] << ' ';
		cout << endl;
		cout.flush();
		exit(0);
	}
	for (int i = ans[d];i <= max(d == n ? n : 1,ans[d]);i++)
	{
		w[d] = as[d] = i;
		dfs(d + 1);
	}
}
 
int main()
{
	cin >> n;
//for (int i = 1;i <= n;i++)
//	cin >> w[i];
	cin >> a[0] >> b[0];
//	pair<int,int> r = calc(0);
//	a[0] = r.first;
//	b[0] = r.second;
	if (n <= 5)
	{
		for (int i = 1;i <= n;i++)
			c[i] = i;
		c[n] = 1;
		for (int i = 1;i <= n;i++)
		{
			cout << "+ " << c[i] << endl;
			cout.flush();
			cin >> a[i] >> b[i];
		//	pair<int,int> r = calc(i);
		//	a[i] = r.first;
		//	b[i] = r.second;
		}
		for (int i = 1;i < n;i++)
			if (a[i] != a[i - 1])
			{
				for (int j = 2;j <= n;j++)
					if ((j + 1) * j * (j - 1) / 6 - j * (j - 1) * (j - 2) / 6 == a[i] - a[i - 1])
					{
						ans[i] = j;
						break;
					}
			}
		if (a[n] != a[n - 1])
		{
			for (int j = 2;j <= n;j++)
				if ((j + 1) * j * (j - 1) / 6 - j * (j - 1) * (j - 2) / 6 == a[n] - a[n - 1])
				{
					ans[1] = j - 1;
					break;
				}
		}
		dfs(1);
	}
	else
	{
		for (int i = 1;i <= n;i++)
		{
			cout << "+ " << i << endl;
			cout.flush();
			cin >> a[i] >> b[i];
		//	pair<int,int> r = calc(i);
		//	a[i] = r.first;
		//	b[i] = r.second;
		}
		for (int i = 1;i <= n;i++)
			if (a[i] != a[i - 1])
			{
				for (int j = 2;j <= n;j++)
					if ((j + 1) * j * (j - 1) / 6 - j * (j - 1) * (j - 2) / 6 == a[i] - a[i - 1])
					{
						ans[i] = j;
						break;
					}
			}
		for (int i = ans[n];i <= max(1,ans[n]);i++)
			for (int j = ans[n - 1];j <= max(1,ans[n - 1]);j++)
				for (int k = ans[n - 2];k <= max(1,ans[n - 2]);k++)
					for (int l = ans[n - 3];l <= max(1,ans[n - 3]);l++)
					{
						as[n] = i;
						as[n - 1] = j;
						as[n - 2] = k;
						as[n - 3] = l;
						if ((k + 1) * (l + 1) + (k + 1) * i != b[n - 1] - b[n - 2])
							continue;
						if ((j + 1) * (k + 1) != b[n] - b[n - 1])
							continue;
						bool ok = 1;
						for (int p = n - 4;p >= 1;p--)
						{
							int v = b[p + 2] - b[p + 1] - as[p + 3] * as[p + 4] - (as[p + 1] + 1) * as[p + 3];
							if (v <= 0 || v % (as[p + 1] + 1) != 0)
							{
								ok = 0;
								break;
							}
							as[p] = v / (as[p + 1] + 1) - 1;
						}
						for (int p = 1;p <= n;p++)
							if (ans[p] && as[p] != ans[p])
								ok = 0;
						ok &= (as[2] * as[3] == b[1] - b[0]);
						ok &= ((as[1] + 1) * as[3] + as[3] * as[4] == b[2] - b[1]);
						if (!ok)
							continue;
						cout << "! ";
						for (int p = 1;p <= n;p++)
							cout << as[p] << ' ';
						cout << endl;
						return 0;
					}
	}
	return 0;
}