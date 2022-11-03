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
const int N = 1e5 + 10;
int a[N];
int b[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		fill(flag + 1, flag + n + 1, 0);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) b[i] = a[i];
		sort(b + 1, b + n + 1);
		for (int i = 1; i + k <= n; i++)
		{
			flag[i] = flag[i + k] = 1;
		}
		int ok = 1;
		int l = INF;
		int r = 0;
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] == 0)
			{
				l = min(l, i);
				r = i;
			}
		}
		for (int i = l; i <= r; i++)
		{
			if (a[i] != b[i])
				ok = 0;
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}