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
const int N = 2e5 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		str[0] = 'R';
		int ans = n + 1;
		int l = 1, r = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			set<int> s;
			for (int i = 1; i <= n + 1; i++)
			{
				s.insert(i);
			}
			queue<int> q;
			q.push(0);
			int flag = 0;
			while (!q.empty())
			{
				int x = q.front();
				q.pop();
				if (x == n + 1)
				{
					flag = 1;
					break;
				}
				int a, b;
				if (str[x] == 'R') a = x, b = x + mid;
				else a = x - mid, b = x;
				while (1)
				{
					auto iter = s.lower_bound(a);
					if (iter == s.end() || *iter > b) break;
					q.push(*iter);
					s.erase(iter);
				}
			}
			if (flag) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}