#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int T,n;

int ans[180];

int main()
{
	for (int i = 1;i < 180;i++)
	{
		for (ans[i] = 3;;ans[i]++)
		{
			bool ok = false;
			for (int j = 1;!ok && j <= ans[i] - 2;j++)
				for (int k = 0;!ok && k <= j - 1;k++)
					if ((j * 180 * ans[i] - j * 180 * (ans[i] - 2)) - (k * 180 * ans[i] - k * 180 * (ans[i] - 2)) == i * 2 * ans[i])
						ok -= true;
			if (ok)
				break;
		}
	}
	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}