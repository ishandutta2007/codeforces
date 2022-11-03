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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
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
		LL sum[2] = { 0,0 };
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			a[i] = x;
			sum[i & 1] += x - 1;
		}
		int o = 0;
		if (sum[0] > sum[1]) o = 1;
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == o) printf("1 ");
			else printf("%d ", a[i]);
		}
		puts("");
	}
	return 0;
}