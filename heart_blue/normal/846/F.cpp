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
const int N = 1e6 + 10;
int pre[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	LL tot = 1000000LL * n * n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		int len = i - pre[x] - 1;
		tot -= 1LL * len * len;
		pre[x] = i;
	}
	for (int i = 1; i <= 1000000; i++)
	{
		int len = n - pre[i];
		tot -= 1LL * len * len;
	}
	printf("%.10f\n", 1.0 * tot / n / n);
	return 0;
}