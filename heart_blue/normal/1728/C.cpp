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
		priority_queue<int> pq1, pq2;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			pq1.emplace(x);
		}
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			pq2.emplace(x);
		}
		int ans = 0;
		while (!pq1.empty() && !pq2.empty())
		{
			if (pq1.top() == pq2.top())
			{
				pq1.pop();
				pq2.pop();
				continue;
			}
			ans++;
			if (pq1.top() > pq2.top())
			{
				int x = pq1.top();
				pq1.pop();
				pq1.push(to_string(x).length());
			}
			else
			{
				int x = pq2.top();
				pq2.pop();
				pq2.push(to_string(x).length());
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}