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
#include <stack>
#include <sstream>
using namespace std;

int main()
{
	int n, a[1111];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j + 1 < n; j++)
		{
			int u = min(a[i], a[i + 1]), v = max(a[i], a[i + 1]);
			int uu = min(a[j], a[j + 1]), vv = max(a[j], a[j + 1]);
			if (u > uu) swap(u, uu), swap(v, vv);
			if (uu > u && uu < v && v < vv)
			{
				puts("yes");
				return 0;
			}
		}
	puts("no");
}