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
const int N = 2e4 + 10;
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
		scanf("%d", &n);
		scanf("%s", str + 1);
		if (count(str + 1, str + n + 1, '1') == n)
		{
			printf("1 %d 1 %d\n", n / 2 * 2, n / 2);
			continue;
		}
		int pos = find(str + 1, str + n + 1, '0') - str;
		if (pos - 1 >= n / 2)
		{
			printf("1 %d 1 %d\n", pos, pos - 1);
		}
		else
		{
			printf("%d %d %d %d\n", pos, n, pos + 1, n);
		}

	}
	return 0;
}