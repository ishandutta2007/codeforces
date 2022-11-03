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
const int N = 3e5 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		char c;
		scanf("%d %c", &n, &c);
		scanf("%s", str + 1);
		if (count(str + 1, str + n + 1, c) == n)
		{
			puts("0");
			continue;
		}
		int key = -1;
		for (int i = 2; i <= n; i++)
		{
			int ok = 1;
			for (int j = i; j <= n; j += i)
			{
				if (str[j] != c)
				{
					ok = 0;
					break;
				}
			}
			if (ok)
				key = i;
		}
		if (key > 0)
		{
			puts("1");
			printf("%d\n", key);
			continue;
		}
		puts("2");
		printf("%d %d\n", n - 1, n);
	}
	return 0;
}