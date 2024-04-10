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
typedef long long LLL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL sum1[N];
LL sum2[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		int x = a[i] - a[i - 1];
		sum1[i] = sum1[i - 1];
		sum2[i] = sum2[i - 1];
		if (x < 0) sum1[i] += -x;
		else sum2[i] += x;
	}
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (l < r) printf("%lld\n", sum1[r] - sum1[l]);
		else printf("%lld\n", sum2[l] - sum2[r]);
	}
	return 0;
}