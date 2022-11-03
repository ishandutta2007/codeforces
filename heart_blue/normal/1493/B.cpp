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
const int N = 5e2 + 10;
int key[] = { 0,1,5,-1,-1,2,-1,-1,8,-1 };
int flag[N];
void init()
{
	MEM(flag, -1);
	for (int i = 0; i < 100; i++)
	{
		int o1 = i / 10;
		int o2 = i % 10;
		if (key[o1] >= 0 && key[o2] >= 0)
			flag[i] = key[o2] * 10 + key[o1];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int h, m;
		scanf("%d%d", &h, &m);
		int x, y;
		scanf("%d:%d", &x, &y);
		while (1)
		{
			if (flag[x] >= 0 && flag[x] < m && flag[y] >= 0 && flag[y] < h)
			{
				break;
			}
			y++;
			if (y == m) y = 0, x++;
			if (x == h) x = 0;
		}
		printf("%02d:%02d\n", x, y);
	}

	return 0;
}