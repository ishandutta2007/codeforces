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
const int N = 3e5 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	int ptr = 1;
	LL ans = 1LL * n * (n + 1) / 2;
	for (int i = 1; i <= n; i++)
	{
		ptr = max(ptr, i + 1);
		while (ptr <= n)
		{
			int flag = 0;
			for (int j = 1; ptr - j * 2 >= i; j++)
			{
				if (str[ptr - j] == str[ptr] && str[ptr - 2 * j] == str[ptr])
				{
					flag = 1;
					break;
				}
			}
			if (flag) break;
			ptr++;
		}
		ans -= ptr - i;
	}
	printf("%lld\n", ans);
	return 0;
}