#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <vector>

using namespace std;

long long n,q,x;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1;i <= q;i++)
	{
		cin >> x;
		if (!(x & 1))
		{
			long long st = (n - 1) - (x - 2) / 2;
			while (!(x & 1))
			{
				x += st;
				st >>= 1;
			}
			cout << (x + 1) / 2 << endl;
		}
		else
			cout << (x + 1) / 2 << endl;
	}
	return 0;
}