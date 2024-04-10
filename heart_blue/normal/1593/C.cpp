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
const int N = 5e1 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		deque<int> q;
		while (k--)
		{
			int x;
			scanf("%d", &x);
			q.push_back(x);
		}
		sort(q.begin(), q.end());
		int cur = 0;
		int ans = 0;
		while (!q.empty())
		{
			cur += n - q.back();
			q.pop_back();
			ans++;
			while (!q.empty() && cur >= q.front())
				q.pop_front();
		}
		printf("%d\n", ans);
	}
	return 0;
}