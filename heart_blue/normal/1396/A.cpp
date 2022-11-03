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
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	if (n == 1)
	{
		puts("1 1");
		printf("%d\n", -a[1]);
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
		return 0;
	}
	printf("2 %d\n", n);
	for (int i = 2; i <= n; i++)
	{
		int o = a[i] % n;
		if (o < 0) o += n;
		a[i] += 1LL * o * (n - 1);
		printf("%lld ", 1LL * o * (n - 1));
	}
	puts("");
	printf("1 %d\n", n);
	printf("0");
	for (int i = 2; i <= n; i++)
	{
		printf(" %lld", -a[i]);
	}
	puts("");
	puts("1 1");
	printf("%lld\n", -a[1]);
	return 0;
}