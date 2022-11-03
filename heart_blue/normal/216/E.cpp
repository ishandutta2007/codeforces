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
map<int, int> tot;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k, b, n;
	scanf("%d%d%d", &k, &b, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	LL res0 = 0;
	{
		LL ans = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0) cnt++;
			else cnt = 0;
			ans += cnt;
		}
		res0 = ans;
	}
	if (b == 0)
	{
		printf("%lld\n", res0);
		return 0;
	}
	k--;
	if (b == k) b = 0;
	tot[0] = 1;
	int sum = 0;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		sum %= k;
		int o = sum - b;
		if (o < 0) o += k;
		ans += tot[o];
		tot[sum]++;
	}
	printf("%lld\n", ans - (b == 0 ? res0 : 0LL));
	return 0;
}