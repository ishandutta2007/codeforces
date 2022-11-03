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
const int N = 3e5 + 10;
int a[N];
int n;
int solve(int pos)
{
	if (pos <= 1 || pos >= n) return 0;
	if (a[pos] > a[pos - 1] && a[pos] > a[pos + 1]) return 1;
	if (a[pos] < a[pos - 1] && a[pos] < a[pos + 1]) return 1;
	return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
		{
			sum += solve(i);
		}
		int ans = sum;
		for (int i = 1; i <= n; i++)
		{
			vector<int> v;
			for (int j = i - 1; j <= i + 1; j++)
			{
				if (j < 1 || j > n) continue;
				for (int o = -1; o <= 1; o++)
					v.push_back(a[j] + o);
			}
			int cur = sum - solve(i - 1) - solve(i) - solve(i + 1);
			v.push_back(a[i]);
			for (auto& y : v)
			{
				a[i] = y;
				ans = min(ans, cur + solve(i - 1) + solve(i) + solve(i + 1));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}