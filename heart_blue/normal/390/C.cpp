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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int sum[N][10];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, w;
	scanf("%d%d%d", &n, &k, &w);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
	{
		memcpy(sum[i], sum[i - 1], sizeof(sum[i]));
		sum[i][i % k] += str[i] - '0';
	}
	while (w--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = 0;
		for (int i = 0; i < k; i++)
		{
			int cnt1 = sum[r][i] - sum[l - 1][i];
			int cnt0 = (r - l + 1) / k - cnt1;
			if (r % k == i) ans += cnt0;
			else ans += cnt1;
		}
		printf("%d\n", ans);
	}
	return 0;
}