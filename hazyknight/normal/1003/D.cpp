#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <cmath> 
#include <iomanip>

using namespace std;

int n,q;
int cnt[35];
int tmp[35];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int a,i = 1;i <= n;i++)
	{
		cin >> a;
		for (int j = 0;j <= 30;j++)
			if (a == (1 << j))
			{
				cnt[j]++;
				break;
			}
	}
	for (int p,i = 1;i <= q;i++)
	{
		cin >> p;
		memcpy(tmp,cnt,sizeof(tmp));
		int ans = 0;
		for (int j = 30;j >= 0;j--)
			if (p & (1 << j))
			{
				for (int k = 30;k >= 0;k--)
				{
					if (tmp[k] <= p / (1 << k))
					{
						p -= tmp[k] * (1 << k);
						ans += tmp[k];
						tmp[k] = 0;
					}
					else
					{
						ans += p / (1 << k);
						tmp[k] -= p / (1 << k);
						p %= (1 << k);
					}
				}
			}
		if (p)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}