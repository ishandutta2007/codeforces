#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long n,x1,x2;
pair<long long,int> c[300005];

bool flag;

void doit()
{
	for (int i = n;i >= 1;i--)
		if (i + (x2 - 1) / c[i].first <= n)
		{
			for (int j = i - 1;j >= 1;j--)
				if (j + (x1 - 1) / c[j].first < i)
				{
					cout << "Yes" << endl;
					if (flag)
					{
						cout << (x2 - 1) / c[i].first + 1 << ' ' << (x1 - 1) / c[j].first + 1 << endl;
						for (int k = i;k <= i + (x2 - 1) / c[i].first;k++)
							cout << c[k].second << ' ';
						cout << endl;
						for (int k = j;k <= j + (x1 - 1) / c[j].first;k++)
							cout << c[k].second << ' ';
						cout << endl;
					}
					else
					{
						cout << (x1 - 1) / c[j].first + 1 << ' ' << (x2 - 1) / c[i].first + 1 << endl;
						for (int k = j;k <= j + (x1 - 1) / c[j].first;k++)
							cout << c[k].second << ' ';
						cout << endl;
						for (int k = i;k <= i + (x2 - 1) / c[i].first;k++)
							cout << c[k].second << ' ';
						cout << endl;
					}
					exit(0);
				}
			return;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> x1 >> x2;
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i].first;
		c[i].second = i;
	}
	sort(c + 1,c + n + 1);
	doit();
	swap(x1,x2);
	flag = true;
	doit();
	cout << "No" << endl;
	return 0;
}