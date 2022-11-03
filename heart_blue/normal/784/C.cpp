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
	int ans = 0;
	int maxv = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ans);
		maxv = max(maxv, ans);
	}
	printf("%d\n", maxv ^ ans);
	return 0;
}