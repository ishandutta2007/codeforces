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
int a[N];
int getans(int l, int r)
{
	int sum = 0;
	int ans = 0;
	for (int i = l; i < r; i++)
	{
		sum = max(a[i], sum + a[i]);
		ans = max(ans, sum);
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int ans = 0;
	for (int o = 1; o <= 30; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > o) continue;
			int j = i;
			while (j <= n && a[j] <= o) j++;
			ans = max(ans, getans(i, j) - o);
			i = j - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}