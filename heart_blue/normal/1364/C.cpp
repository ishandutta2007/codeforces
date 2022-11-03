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
const int N = 1e5 + 10;
int a[N];
int ans[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (a[1] > 1) puts("-1"), exit(0);
	MEM(ans, -1);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1])
			ans[i] = a[i - 1];
	}
	vector<int> v;
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == -1)
		{
			v.push_back(i);
			continue;
		}
		flag[ans[i]] = 1;
		while (cur < a[i])
		{
			if (flag[cur])
			{
				cur++;
				continue;
			}
			if (v.empty())
			{
				puts("-1");
				return 0;
			}
			ans[v.back()] = cur;
			flag[cur++] = 1;
			v.pop_back();
		}
	}
	while (!v.empty())
	{
		ans[v.back()] = n * 2;
		v.pop_back();
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}