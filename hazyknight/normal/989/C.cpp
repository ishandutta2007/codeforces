#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;

int a,b,c,d;

char ans[105][105];

int main()
{
	cin >> a >> b >> c >> d;
	cout << "50 50" << endl;
	a--,b--,c--,d--;
	for (int i = 1;i <= 12;i++)
		for (int j = 1;j <= 50;j++)
			ans[i][j] = 'C';
	for (int i = 13;i <= 25;i++)
		for (int j = 1;j <= 50;j++)
			ans[i][j] = 'D';
	for (int i = 26;i <= 38;i++)
		for (int j = 1;j <= 50;j++)
			ans[i][j] = 'A';
	for (int i = 39;i <= 50;i++)
		for (int j = 1;j <= 50;j++)
			ans[i][j] = 'B';
	for (int i = 1;i <= 12;i += 2)
		for (int j = 1;j <= 50;j += 2)
		{
			if (a)
			{
				ans[i][j] = 'A';
				a--;
			}
		}
	for (int i = 13;i <= 25;i += 2)
		for (int j = 1;j <= 50;j += 2)
		{
			if (b)
			{
				ans[i][j] = 'B';
				b--;
			}
		}
	for (int i = 26;i <= 38;i += 2)
		for (int j = 1;j <= 50;j += 2)
		{
			if (c)
			{
				ans[i][j] = 'C';
				c--;
			}
		}
	for (int i = 39;i <= 50;i += 2)
		for (int j = 1;j <= 50;j += 2)
		{
			if (d)
			{
				ans[i][j] = 'D';
				d--;
			}
		}
	for (int i = 1;i <= 50;i++,cout << endl)
		for (int j = 1;j <= 50;j++)
			cout << ans[i][j];
	return 0;
}