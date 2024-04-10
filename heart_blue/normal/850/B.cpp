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
const int N = 2e6 + 10;
int cnt[N];
LL sum[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= n; i++)
	{
		int val;
		scanf("%d", &val);
		sum[val] += val;
		cnt[val]++;
	}
	for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
	for (int i = 1; i < N; i++) sum[i] += sum[i - 1];
	LL ans = INF * INF;
	for (int i = 2; i < N; i++)
	{
		if (flag[i]) continue;
		for (int j = i; j < N; j += i) flag[j] = 1;
		int step = min(x / y, i - 1);
		LL tot = 0;
		for (int j = i; j < N; j += i)
		{
			LL c1 = cnt[j - 1] - cnt[j - step - 1];
			LL c2 = cnt[j - step-1] - cnt[j - i];
			tot += (c1*j - (sum[j - 1] - sum[j - step - 1]))*y + c2 * x;
		}
		ans = min(ans, tot);
	}
	printf("%lld\n", ans);

	return 0;
}