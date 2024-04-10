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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		int mina = INF, minb = INF;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			mina = min(mina, a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
			minb = min(minb, b[i]);
		}
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += max(a[i] - mina, b[i] - minb);
		}
		printf("%lld\n", ans);
	}
	return 0;
}