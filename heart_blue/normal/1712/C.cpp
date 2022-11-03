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
int a[N];
int flag[N];
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
		int last = 1;
		for (int i = 1; i <= n; i++) flag[i] = i;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			if (flag[a[i]] > flag[a[i + 1]])
			{
				for (int j = last; j <= i; j++)
				{
					if (flag[a[j]])
						flag[a[j]] = 0, ans++;
				}
				last = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}