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
#include <iterator>
#include <complex>
#include <valarray>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N];
int b[N];
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
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			v.push_back(a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
			v.push_back(b[i]);
			if (a[i] > b[i]) swap(a[i], b[i]);
		}
		int ans = INF;
		for (auto& x : v)
		{
			int maxv = 0;
			int flag = 1;
			for (int i = 1; i <= n; i++)
			{
				if (b[i] <= x)
					maxv = max(maxv, a[i]);
				else if (a[i] <= x)
					maxv = max(maxv, b[i]);
				else
					flag = 0;
			}
			if (flag == 0) continue;
			ans = min(ans, x * maxv);
		}
		printf("%d\n", ans);
	}
	return 0;
}