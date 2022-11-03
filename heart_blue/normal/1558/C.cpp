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
int a[N];
int n;
int getpos(int x)
{
	return find(a + 1, a + n + 1, x) - a;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d", &n);
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (abs(i - a[i]) % 2 == 1)
			{
				flag = 0;
			}
		}
		if (flag == 0)
		{
			puts("-1");
			continue;
		}
		vector<int> ans;
		while (n > 1)
		{
			int pos1 = getpos(n);
			ans.push_back(pos1);
			reverse(a + 1, a + pos1 + 1);

			int pos2 = getpos(n - 1);
			ans.push_back(pos2 - 1);
			reverse(a + 1, a + pos2);

			ans.push_back(pos2 + 1);
			reverse(a + 1, a + pos2 + 2);

			pos1 = getpos(n);
			ans.push_back(pos1);
			reverse(a + 1, a + pos1 + 1);

			ans.push_back(n);
			reverse(a + 1, a + n + 1);
			n -= 2;
		}
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
		}
	}
	return 0;
}