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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
char str[N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i + n] = str[i] == 'H';
	int h = count(str + 1, str + n + 1, 'H');
	int t = n - h;
	for (int i = 1; i <= n * 2; i++)
		sum[i] += sum[i - 1];
	int ans = INF;
	for (int i = h; i <= 2 * n; i++)
	{
		ans = min(ans, h - (sum[i] - sum[i - h]));
	}
	for (int i = t; i <= 2 * n; i++)
	{
		ans = min(ans, sum[i] - sum[i - t]);
	}
	cout << ans << endl;
	return 0;
}