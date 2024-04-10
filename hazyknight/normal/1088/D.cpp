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
#include <set>
#include <map>
#include <iomanip>
#include <assert.h>

using namespace std;

int query(int c,int d)
{
	cout << "? " << c << ' ' << d << endl;
	cout.flush();
	int res;
	cin >> res;
	return res;
}

int a,b;

int main()
{
	int preinfo = -2;
	for (int i = 29;i >= 0;i--)
	{
		if (preinfo == -2)
			preinfo = query(a,b);
		if (!preinfo)
		{
			if (query(a | (1 << i),b) == -1)
			{
				a |= (1 << i);
				b |= (1 << i);
			}
		}
		else
		{
			if (preinfo == 1)
			{
				if (query(a | (1 << i),b | (1 << i)) == -1)
				{
					a |= (1 << i);
					preinfo = -2;
				}
				else
				{
					if (query(a | (1 << i),b) == -1)
					{
						a |= (1 << i);
						b |= (1 << i);
					}
				}
			}
			else
			{
				if (query(a | (1 << i),b | (1 << i)) == 1)
				{
					b |= (1 << i);
					preinfo = -2;
				}
				else
				{
					if (query(a | (1 << i),b) == -1)
					{
						a |= (1 << i);
						b |= (1 << i);
					}
				}
			}
		}
	}
	cout << "! " << a << ' ' << b << endl;
	cout.flush();
	return 0;
}