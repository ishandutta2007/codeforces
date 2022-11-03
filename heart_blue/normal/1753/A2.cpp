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
			int x;
			scanf("%d", &x);
			a[i] = x;
			sum += x;
		}
		if (abs(sum) % 2 == 1)
		{
			puts("-1");
			continue;
		}
		if (sum < 0)
		{
			for (int i = 1; i <= n; i++)
				a[i] = -a[i];
			sum = -sum;
		}
		vector<pair<int, int>> ans;
		for (int i = n; i >= 1; i--)
		{
			if (sum == 0 || a[i] != 1)
			{
				ans.emplace_back(i, i);
				continue;
			}
			ans.emplace_back(i - 1, i);
			i--;
			sum -= 2;
		}
		sort(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for (auto& [l, r] : ans)
			printf("%d %d\n", l, r);
	}
	return 0;
}