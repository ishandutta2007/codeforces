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
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (sum % n)
		{
			puts("-1");
			continue;
		}
		int avg = sum / n;
		vector<tuple<int, int, int>> ans;
		for (int i = 2; i <= n; i++)
		{
			if (a[i] % i)
			{
				ans.emplace_back(1, i, i - a[i] % i);
				a[1] -= i - a[i] % i;
				a[i] += i - a[i] % i;
			}
			ans.emplace_back(i, 1, a[i] / i);
			a[1] += a[i];
			a[i] = 0;
		}
		for (int i = 2; i <= n; i++)
		{
			ans.emplace_back(1, i, avg);
		}
		printf("%d\n", ans.size());
		for (auto& p : ans)
		{
			int i, j, x;
			tie(i, j, x) = p;
			printf("%d %d %d\n", i, j, x);
		}
	}
	return 0;
}