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
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	deque<pair<int,int>> q;
	int cnt = 0;
	int flag = 0;
	for (int i = 1; i <= n; i++)
	{
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int cur = hh * 3600 + mm * 60 + ss;
		while (!q.empty() && q.begin()->first < cur)
		{
			q.pop_front();
		}
		if (q.size() == m)
		{
			int id = q.back().second;
			q.pop_back();
			q.emplace_back(cur + t - 1, id);
			ans[i] = id;
		}
		else
		{
			q.emplace_back(cur + t - 1, ++cnt);
			ans[i] = cnt;
		}
		if (q.size() == m)
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		puts("No solution");
		return 0;
	}
	else
	{
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}