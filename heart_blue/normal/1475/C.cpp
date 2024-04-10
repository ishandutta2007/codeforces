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
int cnt1[N];
int cnt2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &a[i]);
			cnt1[a[i]] = 0;
		}
		for (int i = 1; i <= k; i++) cnt1[a[i]]++;
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &b[i]);
			cnt2[b[i]] = 0;
		}
		for (int i = 1; i <= k; i++) cnt2[b[i]]++;
		LL ans = 0;
		for (int i = 1; i <= k; i++)
		{
			ans += k - cnt1[a[i]] - cnt2[b[i]] + 1;
		}
		printf("%lld\n", ans / 2);
	}
	return 0;
}