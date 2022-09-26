#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

long long k1,k2,k3;

bool check(int i,int j,int k)
{
	for (int p = 1;p <= k1 * k2 * k3;p++)
		if (p % k1 != i && p % k2 != j && p % k3 != k)
			return false;
	return true;
}

int main()
{
	cin >> k1 >> k2 >> k3;
	if (k1 * k2 + k2 * k3 + k3 * k1 < k1 * k2 * k3)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0;i < k1;i++)
		for (int j = 0;j < k2;j++)
			for (int k = 0;k < k3;k++)
				if (check(i,j,k))
				{
					cout << "YES" << endl;
					return 0;
				}
	cout << "NO" << endl;
	return 0;
}