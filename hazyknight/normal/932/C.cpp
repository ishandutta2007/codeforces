#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int n,a,b;

int main()
{
	cin >> n >> a >> b;
	for (int i = 0;i <= n;i += a)
	{
		if ((n - i) % b == 0)
		{
			int cnta = i / a,cntb = (n - i) / b;
			for (int j = 1;j <= cnta;j++)
			{
				for (int k = (j - 1) * a + 1;k < j * a;k++)
					cout << k + 1 << ' ';
				cout << (j - 1) * a + 1 << ' ';
			}
			for (int j = 1;j <= cntb;j++)
			{
				for (int k = i + (j - 1) * b + 1;k < i + j * b;k++)
					cout << k + 1 << ' ';
				cout << i + (j - 1) * b + 1 << ' ';
			}
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}