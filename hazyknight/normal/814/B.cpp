#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,top;
int a[1005];
int b[1005];

bool mark[1005];

int flag[2];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> b[i];
		if (a[i] != b[i])
			flag[top++] = i;
	}
	if (top == 0)
	{
		int pos = 0;
		for (int i = 1;i <= n;i++)
		{
			if (mark[a[i]])
				pos = i;
			mark[a[i]] = true;
		}
		for (int i = 1;i <= n;i++)
			if (!mark[i])
			{
				a[pos] = i;
				break;
			}
		for (int i = 1;i <= n;i++)
			cout << a[i] << ' ';
		cout << endl;
	}
	else if (top == 1)
	{
		for (int i = 1;i <= n;i++)
			mark[a[i]] = true;
		for (int i = 1;i <= n;i++)
			if (!mark[i])
			{
				a[flag[0]] = i;
				break;
			}
		for (int i = 1;i <= n;i++)
			cout << a[i] << ' ';
		cout << endl;
	}
	else
	{
		int tmp = a[flag[0]],ok = 1;
		a[flag[0]] = b[flag[0]];
		for (int i = 1;i <= n;i++)
		{
			if (mark[a[i]])
			{
				ok = false;
				break;
			}
			mark[a[i]] = true;
		}
		if (!ok)
		{
			a[flag[0]] = tmp;
			a[flag[1]] = b[flag[1]];
		}
		for (int i = 1;i <= n;i++)
			cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}