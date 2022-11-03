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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		int a[4];
		cin >> n;
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		int mask = 1 << 4;
		int flag = 0;
		for (int o = 0; o < mask; o++)
		{
			int b[] = { o >> 0 & 1,o >> 1 & 1,o >> 2 & 1,o >> 3 & 1 };
			flag = 1;
			for (int i = 0; i < 4; i++)
			{
				int x = a[i] - b[i] - b[(i + 1) % 4];
				if (x < 0 || x > n - 2)
				{
					flag = 0;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}