#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>

using namespace std;

int l[5],r[5],m[5],p[5];

int c(int p)
{
	return p == 0 ? 4 : p;
}

int main()
{
	for (int i = 1;i <= 4;i++)
		cin >> l[i] >> m[i] >> r[i] >> p[i];
	for (int i = 1;i <= 4;i++)
	{
		if (l[i] && (p[i] || p[c((i + 3) & 3)]))
		{
			cout << "Yes" << endl;
			return 0;
		}
		if (r[i] && (p[i] || p[c((i + 1) & 3)]))
		{
			cout << "Yes" << endl;
			return 0;
		}
		if (m[i] && (p[i] || p[c((i + 2) & 3)]))
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}