#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int n;
int a[55][55];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			cin >> a[i][j];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (a[i][j] != 1)
			{
				bool flag = false;
				for (int k = 1;k <= n && !flag;k++)
					for (int l = 1;l <= n;l++)
						if (a[i][k] + a[l][j] == a[i][j])
						{
							flag = true;
							break;
						}
				if (!flag)
				{
					cout << "No" << endl;
					return 0;
				}
			}
	cout << "Yes" << endl;
	return 0;
}