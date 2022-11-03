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
		for (int i = 0; i <= 2 * n + 1; i++) a[i] = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			a[x]++;
		}
		for (int i = 2 * n; i >= 1; i--)
		{
			if (a[i] > 0)
			{
				if (a[i + 1] == 0) a[i]--, a[i + 1]++;
			}
		}
		int ans = 0;
		for (int i = 1; i <= 2 * n + 1; i++)
			ans += a[i] > 0;
		printf("%d\n", ans);
	}
	return 0;
}