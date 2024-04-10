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
const int N = 4e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		list<int> ls;
		double cur1 = 1, cur2 = 1;
		int n, len;
		scanf("%d%d", &n, &len);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			ls.push_back(x);
		}
		double l = 0, r = len;
		double ans = 0;
		while (!ls.empty())
		{
			double minv = min((ls.front() - l) / cur1, (r - ls.back()) / cur2);
			l += minv * cur1;
			r -= minv * cur2;
			ans += minv;
			if (ls.front() - l < r - ls.back()) ls.pop_front(), cur1++;
			else ls.pop_back(), cur2++;
		}
		ans += 1.0 * (r - l) / (cur1 + cur2);
		printf("%.15f\n", ans);
	}
	return 0;
}