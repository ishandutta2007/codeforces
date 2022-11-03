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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		int x;
		scanf("%*d.%d", &x);
		if (x == 0) cnt++;
		else sum += x;
	}
	int ans = INF;
	int maxv = min(2 * n - cnt, n);
	int minv = max(0, n - cnt);
	for (int i = minv; i <= maxv; i++)
	{
		ans = min(ans, abs(sum - i * 1000));
	}
	printf("%d.%03d\n", ans / 1000, ans % 1000);
	return 0;
}