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
const int N = 1e2 + 30;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, x;
		cin >> n >> x;
		int flag = 0;
		int maxv = 0;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			if (a == x) flag = x;
			maxv = max(maxv, a);
		}
		if (flag)
		{
			puts("1");
			continue;
		}
		if (x < maxv)
		{
			puts("2");
			continue;
		}
		printf("%d\n", (x + maxv - 1) / maxv);
	}
	return 0;
}