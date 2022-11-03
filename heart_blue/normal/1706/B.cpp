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
const int N = 2e5 + 10;
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
		map<pair<int, int>, int> mc;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[{x, i & 1}] = max(mc[{x, i & 1}], mc[{x, (i & 1) ^ 1}] + 1);
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", max(mc[{i, 0}], mc[{i, 1}]), " \n"[i == n]);
		}
	}

	return 0;
}