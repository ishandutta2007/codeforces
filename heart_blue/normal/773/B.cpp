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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N][5];
vector<pair<int, int>> vp[10];
int cnt[5];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] >= 0)
				cnt[j]++;
		}
	}
	const int M = 32 * 120;
	for (int o = 0; o <= M; o++)
	{
		int tot = 0;
		for (int i = 0; i < 5; i++)
		{
			int u = 0, d = 0;
			if (a[1][i] == -1) u = cnt[i], d = o + n;
			else if (a[2][i] == -1) u = cnt[i], d = o + n;
			else if (a[1][i] <= a[2][i]) u = cnt[i], d = o + n;
			else u = cnt[i] + o, d = o + n;
			int s = 0;
			for (int j = 2; j <= 64; j *= 2)
			{
				s++;
				if (u * j > d)
				{
					break;
				}
			}
			int x = 0, y = 0;
			s *= 500;
			if (a[1][i] != -1) x = s - s * a[1][i] / 250;
			if (a[2][i] != -1) y = s - s * a[2][i] / 250;
			tot += x - y;
		}
		if (tot > 0)
		{
			printf("%d\n", o);
			return 0;
		}
	}
	puts("-1");
	return 0;
}