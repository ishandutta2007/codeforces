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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; i--)
	{
		if (a[i] >= 0)
		{
			int x = a[i];
			while (!pq.empty())
			{
				int y = pq.top();
				pq.pop();
				int o = min(x, y);
				x -= o;
				y -= o;
				if (y > 0) pq.push(y);
				if (x == 0) break;
			}
		}
		else
		{
			pq.emplace(-a[i]);
		}
	}
	printf("%d\n", n - (int)pq.size());
	return 0;
}