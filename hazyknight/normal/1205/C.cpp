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

const int MAXN = 55;

int n,r;
int a[MAXN][MAXN];

int main()
{
	cin >> n;
	memset(a,-1,sizeof(a));
	a[1][1] = 1;
	a[1][2] = 0;
	a[n][n] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (((i + j) % 2 == 0 || j > 1) && a[i][j] == -1)
			{
				if (j - 2 >= 1 && ((i + j) % 2 == 0 || j > 3))
				{
					cout << "? " << i << ' ' << j - 2 << ' ' << i << ' ' << j << endl;
					cout.flush();
					cin >> r;
					if (r)
						a[i][j] = a[i][j - 2];
					else
						a[i][j] = a[i][j - 2] ^ 1;
				}
				else if (i - 2 >= 1)
				{
					cout << "? " << i - 2 << ' ' << j << ' ' << i << ' ' << j << endl;
					cout.flush();
					cin >> r;
					if (r)
						a[i][j] = a[i - 2][j];
					else
						a[i][j] = a[i - 2][j] ^ 1;
				}
				else
				{
					cout << "? " << i - 1 << ' ' << j - 1 << ' ' << i << ' ' << j << endl;
					cout.flush();
					cin >> r;
					if (r)
						a[i][j] = a[i - 1][j - 1];
					else
						a[i][j] = a[i - 1][j - 1] ^ 1;
				}
			}
	for (int i = 1;i <= n;i++)
		if (~i & 1)
		{
			cout << "? " << i << ' ' << 1 << ' ' << i + 1 << ' ' << 2 << endl;
			cout.flush();
			cin >> r;
			if (r)
				a[i][1] = a[i + 1][2];
			else
				a[i][1] = a[i + 1][2] ^ 1;
		}
	int ok = -1;
	for (int i = 1;ok == -1 && i + 2 <= n;i++)
		for (int j = 1;ok == -1 && j + 2 <= n;j++)
			if ((i + j) % 2 == 0 && a[i][j] != a[i + 2][j + 2])
			{
				cout << "? " << i << ' ' << j << ' ' << i + 2 << ' ' << j + 1 << endl;
				cout.flush();
				cin >> r;
				if (r)
				{
					ok = (a[i][j] != a[i + 2][j + 1]);
					break;
				}
				cout << "? " << i + 1 << ' ' << j << ' ' << i + 2 << ' ' << j + 2 << endl;
				cout.flush();
				cin >> r;
				if (r)
				{
					ok = (a[i + 1][j] != a[i + 2][j + 2]);
					break;
				}
				if (a[i + 1][j + 1] == a[i][j])
					ok = (a[i][j] == a[i + 2][j + 1]);
				else
					ok = (a[i + 1][j] == a[i + 2][j + 2]);
			}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if ((i + j) % 2 == 1)
				a[i][j] ^= ok;
	cout << "!" << endl;
	for (int i = 1;i <= n;i++,cout << endl)
		for (int j = 1;j <= n;j++)
			cout << a[i][j];
	cout.flush();
	return 0;
}