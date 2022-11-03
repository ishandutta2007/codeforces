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
const int N = 1e2 + 10;
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
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (n == 1)
			{
				ans = 1;
				break;
			}
			vector<int> v;
			int tot = 0;
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				v.push_back(a[j]);
				tot += a[j];
			}
			sort(v.begin(), v.end());
			int rest = v.back() - (tot - v.back());
			rest = max(rest, 0);
			if (rest < a[i])
			{
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}