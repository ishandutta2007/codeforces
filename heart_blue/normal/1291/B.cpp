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
		int left = 1;
		int right = n;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		int pre;
		pre = -1;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] <= pre) break;
			else pre = pre + 1;
			left = i;
		}
		pre = -1;
		for (int i = n; i >= 1; i--)
		{
			if (a[i] <= pre) break;
			else pre = pre + 1;
			right = i;
		}
		if (left >= right) puts("Yes");
		else puts("No");
	}

	return 0;
}