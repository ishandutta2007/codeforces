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
const int N = 2e3 + 10;
int v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	int ks = 1;
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		int mask = n - 1;
		int k;
		scanf("%d", &k);
		if (k == 0)
		{
			for (int i = 0; i < n / 2; i++)
				printf("%d %d\n", i, mask ^ i);
		}
		else if (k != n - 1)
		{
			printf("%d %d\n", k, mask);
			printf("%d %d\n", k ^ mask, 0);
			k = min(k, k ^ mask);
			for (int i = 1; i < n / 2; i++)
			{
				if (i == k) continue;
				printf("%d %d\n", i, mask ^ i);
			}
		}
		else
		{
			if (n == 4) 
			{
			    puts("-1");
			    continue;
			}
			printf("%d %d\n", n - 1, n - 2);
			printf("%d %d\n", 1, n - 3);
			printf("%d %d\n", 0, 2);
			for (int i = 3; i < n / 2; i++)
				printf("%d %d\n", i, mask ^ i);
		}
	}
	return 0;
}