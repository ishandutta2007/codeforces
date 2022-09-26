#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

long long n,k,ans;

int main()
{
	cin >> n >> k;
	if (k == 1)
		cout << n << endl;
	else
	{
		for (int i = 62;i >= 0;i--)
			if (n >= (1ll << i))
			{
				cout << (1ll << (i + 1)) - 1 << endl;
				return 0;
			}
	}
	return 0;
}