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
int b[N];
int check(int n, int o = 0)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (b[i] >= o) cnt++, o ^= 1;
	}
	return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int l = 0, r = INF;
	int ans = INF;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		for (int i = 1; i <= n; i++)
		{
			b[i] = a[i] <= mid;
		}
		if (check(n, 0) >= k || check(n, 1) >= k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}