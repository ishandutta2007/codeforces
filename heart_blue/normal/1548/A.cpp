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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int tot = 0;
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > y) swap(x, y);
		if (flag[x]++ == 0) tot++;
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1 || op == 2)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (x > y) swap(x, y);
			if (op == 1)
			{
				if (flag[x]++ == 0) tot++;
			}
			else
			{
				if (flag[x]-- == 1) tot--;
			}
		}
		else
		{
			printf("%d\n", n - tot);
		}
	}
	return 0;
}