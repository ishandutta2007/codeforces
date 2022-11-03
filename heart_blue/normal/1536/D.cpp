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
const int N = 4e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int ptr = 0;
		int n;
		scanf("%d", &n);
		int flag = 1;
		set<int> s;
		int last = -1;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (flag == 0) continue;
			if (i == 1)
			{
				s.insert(x);
				last = x;
				continue;
			}
			if (x == last) continue;
			if (x > last)
			{
				auto iter = s.upper_bound(last);
				if (iter != s.end() && *iter < x)
				{
					flag = 0;
				}
			}
			else
			{
				auto iter = s.lower_bound(last);
				if (iter != s.begin() && *(--iter) > x)
				{
					flag = 0;
				}
			}
			s.insert(x);
			last = x;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}