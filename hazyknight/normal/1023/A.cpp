#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,m;

string a,b;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> a >> b;
	int pos = -1;
	for (int i = 0;i < n;i++)
		if (a[i] == '*')
		{
			pos = i;
			break;
		}
	if (pos == -1)
	{
		if (a == b)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}
	if (n - 1 > m)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0;i < pos;i++)
		if (b[i] != a[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	for (int i = n - 1;i > pos;i--)
		if (b[m - n + i] != a[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}