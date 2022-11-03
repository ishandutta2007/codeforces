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
int cnt[N];
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
		int flag = 0;
		fill(cnt, cnt + n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			cnt[x]++;
		}
		LL sum = 0;
		printf("%d", cnt[0]);
		priority_queue<int> pq;
		for (int i = 1; i < cnt[0]; i++)
			pq.emplace(0);
		for (int i = 1; i <= n; i++)
		{
			if (cnt[i - 1] == 0)
			{
				if (pq.empty())
					flag = -1;
				else
				{
					sum += (i - 1) - pq.top();
					pq.pop();
				}
			}
			if (flag == -1)
			{
				printf(" %d", -1);
				continue;
			}
			printf(" %lld", sum + cnt[i]);
			while (cnt[i] > 1)
			{
				pq.emplace(i);
				cnt[i]--;
			}
		}
		puts("");
	}
	return 0;
}