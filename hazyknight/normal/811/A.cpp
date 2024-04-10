#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int cnt[2];

int main()
{
	cin >> cnt[1] >> cnt[0];
	for (int i = 1;;i++)
	{
		int now = (i & 1);
		if (cnt[now] < i)
		{
			cout << ((now == 1) ? "Vladik" : "Valera") << endl;
			return 0;
		}
		cnt[now] -= i;
	}
	return 0;
}