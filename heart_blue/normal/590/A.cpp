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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int ans = 0;
	int pre = 0;
	for (int i = 1; i < n; i++)
	{
		if (i != n - 1 && a[i] != a[i - 1] && a[i] != a[i + 1]) continue;
		ans = max(ans, (i - pre) / 2);
		if (a[i] == a[pre])
		{
			for (int j = pre; j <= i; j++) a[j] = a[i];
		}
		else
		{
			for (int j = 0; pre + j < i - j; j++) a[i - j] = a[i], a[pre + j] = a[pre];
		}
		pre = i;
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}