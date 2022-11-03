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
const int N = 3e5 + 10;
pair<int, int> a[N];
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i].first;
	}
	LL cur = 0;
	LL ans = 0;
	int id = 1;
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		cur += ((i - 1) * 2 + (1 - k)) * 1LL * a[i].first;
	}
	ans = cur;
	for (int i = 2; i + k - 1 <= n; i++)
	{
		cur += (k - 1) * 1LL * (a[i + k - 1].first + a[i - 1].first);
		cur -= 2 * (sum[i + k - 2] - sum[i - 1]);
		if (cur < ans)
		{
			id = i;
			ans = cur;
		}
	}
	for (int j = 0; j < k; j++)
		printf("%d%c", a[j + id].second, " \n"[j + 1 == k]);
	return 0;
}