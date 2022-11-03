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
const int N = 2e5 + 10;
vector<pair<int, int>> a;
int solve(vector<int>& v, int n, int h)
{
	if (v.back() == 1)
	{
		return a[n - 1].first + a[n - 2].first - a[1].first - a[0].first;
	}
	else
	{
		int minv = min(a[0].first + a[1].first + h, a[1].first + a[2].first);
		int maxv = max(a[0].first + a[n - 1].first + h, a[n - 1].first + a[n - 2].first);
		return maxv - minv;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, h;
	scanf("%d%d", &n, &h);
	if (n == 2)
	{
		puts("0");
		puts("1 1");
		return 0;
	}
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<int> v1(n, 1), v2(n, 2);
	v2[0] = 1;
	int res = min(solve(v1, n, h), solve(v2, n, h));
	printf("%d\n", res);
	if (solve(v1, n, h) < solve(v2, n, h))
	{
		while (n--) printf("1 ");
	}
	else
	{
		int id = a[0].second;
		for (int i = 0; i < n; i++)
		{
			if (i == id) printf("2 ");
			else printf("1 ");
		}
	}
	return 0;
}