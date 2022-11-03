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
int ans[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i * 2 - 1] = a[i * 2] = x;
		vp.emplace_back(x, i * 2 - 1);
	}
	sort(vp.rbegin(), vp.rend());
	for (int i = 1; i <= n; i++)
	{
		ans[i] = vp[i - 1].second;
	}
	int maxv = n;
	for (int i = 1; i <= n; i++)
	{
		int t = i + a[ans[i]];
		maxv = max(maxv, t);
		if (ans[t] == 0)
		{
			ans[t] = ans[i] + 1;
		}
		else
		{
			t--;
			printf("%d %d\n", ans[t], ans[i] + 1);
		}
	}
	for (int i = 1; i < maxv; i++)
	{
		printf("%d %d\n", ans[i], ans[i + 1]);
	}
	return 0;
}