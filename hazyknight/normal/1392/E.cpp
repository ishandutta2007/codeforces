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
#include <bitset>

using namespace std;

typedef long long ll;

int n,q;

ll a[30][30];

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++,cout << endl)
		for (int j = 0;j < n;j++)
		{
			a[i][j] = (1ll << (i + j)) * min(j,n - 1 - i);
			cout << a[i][j] << ' ';
		}
	cout.flush();
	cin >> q;
	while (q--)
	{
		ll sum = 0;
		cin >> sum;
		sum -= a[0][0];
		int x = 0,y = 0;
		while (x != n - 1 || y != n - 1)
		{
			cout << x + 1 << ' ' << y + 1 << endl;
			if (x == n - 1)
				y++;
			else if (y == n - 1)
				x++;
			else
			{
				sum -= a[x + 1][y];
				if (sum >> (x + y + 1) & 1)
				{
					sum -= a[x][y + 1] - a[x + 1][y];
					y++;
				}
				else
					x++;
			}
		}
		cout << n << ' ' << n << endl;
		cout.flush();
	}
	return 0;
}