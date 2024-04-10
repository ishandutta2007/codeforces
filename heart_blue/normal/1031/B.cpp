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
const int N = 3e5 + 10;
int a[N];
int b[N];
int pre[N][4];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(pre, -1);
	MEM(pre[1], 0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) cin >> b[i];
	for (int i = 2; i <= n; i++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (pre[i - 1][x] == -1) continue;
			for (int y = 0; y < 4; y++)
			{
				if ((x | y) != a[i - 1]) continue;
				if ((x & y) != b[i - 1]) continue;
				pre[i][y] = x;
			}
		}
	}
	int o = -1;
	for (int i = 0; i < 4; i++)
	{
		if (pre[n][i] == -1) continue;
		o = i;
		break;
	}
	if (o == -1)
	{
		puts("NO");
		return 0;
	}
	for (int i = n; i >= 1; i--)
	{
		ans[i] = o;
		o = pre[i][o];
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}