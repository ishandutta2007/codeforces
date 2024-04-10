#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
using namespace std;

int n, a[25], bit[1 << 22];
bool f[25][1 << 22];
vector < pair<int,int> > eq[25];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	if (n == 1) 
	{
		puts("1");
		return 0;
	}
	
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			for (int k = j; k < i; k++)
				if (a[k] + a[j] == a[i])
					eq[i].push_back(make_pair(j, k));
	
	for (int mask = 1; mask < 1 << 22; mask++) 
		bit[mask] = bit[mask ^ (mask & -mask)] + 1;
	
	f[0][1] = 1;
	int ans = n;
	
	for (int i = 1; i < n; i++)
		for (int mask = 1; mask < 1 << i; mask++)
			if (f[i - 1][mask])
				for (int j = 0; j < int(eq[i].size()); j++)
				{
					int x = eq[i][j].first, y = eq[i][j].second;
					if (!(mask >> x & 1) || !(mask >> y & 1)) continue;
					
					if (i == n - 1)
					{
						ans = min(ans, bit[mask]);
						continue;
					}
					
					int newMask = mask | 1 << i;
					f[i][newMask] = 1;
					int tmpMask = mask;
					while (tmpMask)
					{
						int lsb = tmpMask & -tmpMask;
						f[i][newMask ^ lsb] = 1;
						tmpMask ^= lsb;
					}
					break;
				}
	
	if (ans == n) puts("-1");
	else cout << ans << endl;
}