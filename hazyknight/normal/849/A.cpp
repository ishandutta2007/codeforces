#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
int a[105];
int f[105][2];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	if (!(a[1] & 1))
	{
		cout << "No" << endl;
		return 0;
	}
	f[0][0] = 1;
	f[1][1] = 1;
	for (int i = 2;i <= n;i++)
		if (a[i] & 1)
		{
			for (int j = i;j >= 1;j -= 2)
				if ((a[j] & 1) && (j == 1 || a[j - 1] & 1))
				{
					f[i][0] |= f[j - 1][1];
					f[i][1] |= f[j - 1][0];
				}
		}
	cout << ((f[n][1] == true) ? "Yes" : "No") << endl;
	return 0;
}