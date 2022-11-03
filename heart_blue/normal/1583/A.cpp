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
const int N = 2e5 + 10;
bool check(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0) return true;
	}
	return false;
}
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
		vector<int> v(n);
		vector<int> ans;
		for (int i = 1; i <= n; i++) ans.push_back(i);
		int sum = 0;
		for (auto& x : v)
		{
			scanf("%d", &x);
			sum += x;
		}
		if (!check(sum))
		{
			for (int i = 1; i <= n; i++)
			{
				if (v[i - 1] & 1)
				{
					ans.erase(ans.begin() + i - 1);
					break;
				}
			}
		}
		printf("%d\n", ans.size());
		for (auto& x : ans)
			printf("%d ", x);
		puts("");

	}
	return 0;
}