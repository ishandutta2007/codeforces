#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,k;
int a[105];

int main()
{
	cin >> n >> k;
	if (k > 1)
		cout << "Yes" << endl;
	else
	{
		int flag = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
			if (a[i] == 0)
				flag = i;
		}
		cin >> a[flag];
		for (int i = 1;i < n;i++)
			if (a[i] > a[i + 1])
			{
				cout << "Yes" << endl;
				return 0;
			}
		cout << "No" << endl;
	}
	return 0;
}