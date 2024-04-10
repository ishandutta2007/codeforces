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
int flag[N];
int getans(int n)
{
	for (int i = 0; i <= n; i++) flag[i] = 0;
	for (int i = 0; i < n; i++) flag[a[i]] = 1;
	int key = n;
	for (int i = 0; i <= n; i++)
	{
		if (flag[i] == 0)
		{
			key = i;
			break;
		}
	}
	return key;
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
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int tot = 2 * n;
		vector<int> ans;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == i) continue;
			int cur = getans(n);
			while (cur != i)
			{
				if (cur < n && a[cur] != cur)
				{
					a[cur] = cur;
					ans.push_back(cur + 1);
					cur = getans(n);
					continue;
				}
				for (int j = i + 1; j < n; j++)
				{
					if (a[j] == i)
					{
						ans.push_back(j + 1);
						a[j] = cur;
						break;
					}
				}
				cur = getans(n);
			}
			a[i] = i;
			ans.push_back(i + 1);
		}
		printf("%d\n", ans.size());
		for (auto& x : ans)
			printf("%d ", x);
		puts("");
	}
	return 0;
}