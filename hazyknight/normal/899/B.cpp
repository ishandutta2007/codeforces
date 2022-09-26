#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int n;
int a[30];
int bb1[48] = {31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int bb2[48] = {31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int bb3[48] = {31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int bb4[48] = {31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int bb5[48] = {31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	for (int i = 0;i <= 48 - n;i++)
	{
		bool ok = true;
		for (int j = 0;j < n;j++)
			if (a[j] != bb1[i + j])
			{
				ok = false;
				break;
			}
		if (ok)
		{
		    cout << "YES" << endl;
		    return 0;
		}
	}
	for (int i = 0;i <= 48 - n;i++)
	{
		bool ok = true;
		for (int j = 0;j < n;j++)
			if (a[j] != bb2[i + j])
			{
				ok = false;
				break;
			}
		if (ok)
		{
		    cout << "YES" << endl;
		    return 0;
		}
	}
	for (int i = 0;i <= 48 - n;i++)
	{
		bool ok = true;
		for (int j = 0;j < n;j++)
			if (a[j] != bb3[i + j])
			{
				ok = false;
				break;
			}
		if (ok)
		{
		    cout << "YES" << endl;
		    return 0;
		}
	}
	for (int i = 0;i <= 48 - n;i++)
	{
		bool ok = true;
		for (int j = 0;j < n;j++)
			if (a[j] != bb4[i + j])
			{
				ok = false;
				break;
			}
		if (ok)
		{
		    cout << "YES" << endl;
		    return 0;
		}
	}
	for (int i = 0;i <= 48 - n;i++)
	{
		bool ok = true;
		for (int j = 0;j < n;j++)
			if (a[j] != bb5[i + j])
			{
				ok = false;
				break;
			}
		if (ok)
		{
		    cout << "YES" << endl;
		    return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}