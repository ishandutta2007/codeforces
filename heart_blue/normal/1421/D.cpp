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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		for (int i = 1; i <= 6; i++) cin >> a[i];
		int cnt = 100;
		while (cnt--)
		{
			for (int i = 1; i <= 6; i++)
			{
				int x = i + 1;
				int y = i - 1;
				if (x > 6) x -= 6;
				if (y < 1) y += 6;
				a[i] = min(a[i], a[x] + a[y]);
			}
		}
		LL ans = 0;
		if (x > 0 && y > 0)
		{
			int o = min(x, y);
			x -= o;
			y -= o;
			ans += 1LL * o * a[1];
		}
		if (x < 0 && y < 0)
		{
			int o = max(x, y);
			x -= o;
			y -= o;
			ans += 1LL * -o * a[4];
		}
		if (y > 0) ans += 1LL * y * a[2];
		else ans += 1LL * -y * a[5];
		if (x > 0) ans += 1LL * x * a[6];
		else ans += 1LL * -x * a[3];
		printf("%lld\n",ans);
	}
	return 0;
}