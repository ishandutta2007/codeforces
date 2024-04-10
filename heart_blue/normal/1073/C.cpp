#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int lpx[N], lpy[N];
int rpx[N], rpy[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n;
	cin >> str;
	int x, y;
	cin >> x >> y;
	int cx = 0, cy = 0;
	int ud = 0, lr = 0;
	for(int i = 1; i <= n; i++)
	{
		char c = str[i - 1];
		if (c == 'U') cy++;
		if (c == 'D') cy--;
		if (c == 'L') cx--;
		if (c == 'R') cx++;
		lpx[i] = cx;
		lpy[i] = cy;
	}
	if (cx == x && cy == y)
	{
		puts("0");
		return 0;
	}
	cx = 0, cy = 0;
	for (int i = n; i >= 1; i--)
	{
		char c = str[i - 1];
		if (c == 'U') cy++;
		if (c == 'D') cy--;
		if (c == 'L') cx--;
		if (c == 'R') cx++;
		rpx[i] = cx;
		rpy[i] = cy;
	}
	if (abs(x) + abs(y) > str.length())
	{
		puts("-1");
		return 0;
	}
	if ((abs(x) + abs(y) + abs(cx) + abs(cy)) % 2 == 1)
	{
		puts("-1");
		return 0;
	}
	int l = 1, r = n;
	int ans = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int flag = 0;
		for (int i = 1; i + mid - 1 <= n; i++)
		{
			int tx = lpx[i - 1] + rpx[i + mid];
			int ty = lpy[i - 1] + rpy[i + mid];
			int rest = abs(tx - x) + abs(ty - y);
			if (rest <= mid)
			{
				flag = 1;
				break;
			}
		}
		if (flag) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	
	printf("%d\n", ans);
	return 0;
}