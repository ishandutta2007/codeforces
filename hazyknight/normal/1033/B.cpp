#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

long long t,a,b;

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		if (a - b != 1)
		{
			cout << "NO" << endl;
			continue;
		}
		a += b;
		bool ok = false;
		for (long long i = 2;i * i <= a;i++)
			if (a % i == 0)
			{
				cout << "NO" << endl;
				ok = true;
				break;
			}
		if (!ok)
			cout << "YES" << endl;
	}
	return 0;
}