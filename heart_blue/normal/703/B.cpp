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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
LL cost[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> cost[i];
	MEM(flag, 0);
	for (int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		flag[x] = 1;
	}
	LL ans = 0;
	LL a = 0, b = 0;
	for (int i = 1; i <= n; i++)
	{
		int t = i - 1;
		if (t == 0) t = n;
		if (flag[i] == 0 && flag[t] == 0)
		{
			ans += cost[i] * cost[t];
		}
		if (flag[i] == 0) a += cost[i];
		else b += cost[i];
	}
	ans += a*b;
	LL tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 1) tmp += (b - cost[i]) *cost[i];
	}
	ans += tmp / 2;
	cout << ans << endl;
	return 0;
}