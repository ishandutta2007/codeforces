#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <ctime>

using namespace std;

int main()
{
	int l,r;
	cin >> l >> r;
	if (l == r)
	{
		bool ok = false;
		for (int i = 2;i * i <= l;i++)
			if (l % i == 0)
			{
				cout << i << endl;
				ok = true;
				break;
			}
		if (!ok)
			cout << l << endl;
	}
	else
		cout << 2 << endl;
	return 0;
}