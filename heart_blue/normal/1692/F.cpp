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
#include <complex>
#include <random>
#include <chrono>
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
	scanf("%d", &ncase);
	while (ncase--)
	{
		int cnt[10];
		MEM(cnt, 0);
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int x;
			scanf("%d", &x);
			cnt[x % 10]++;
		}
		int flag = 0;
		for (int i = 0; i <= 9; i++)
		{
			if (cnt[i] < 3) continue;
			if ((i * 3) % 10 == 3)
				flag = 1;
		}
		for (int i = 0; i <= 9; i++)
		{
			if (cnt[i] < 2) continue;
			for (int j = 0; j <= 9; j++)
			{
				if (i == j) continue;
				if (cnt[j] < 1) continue;
				if ((i * 2 + j) % 10 == 3)
					flag = 1;
			}
		}
		for (int i = 0; i <= 9; i++)
		{
			if (cnt[i] == 0) continue;
			for (int j = 0; j <= 9; j++)
			{
				if (i == j) continue;
				if (cnt[j] == 0) continue;
				for (int k = 0; k <= 9; k++)
				{
					if (i == k || j == k) continue;
					if (cnt[k] == 0) continue;
					if ((i + j + k) % 10 == 3)
						flag = 1;
				}
			}
		}
		if (flag) puts("Yes");
		else puts("No");
	}

	return 0;
}