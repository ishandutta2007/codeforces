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
LL cost[N];
LL a, b, t;
int n;
int getans()
{
	int ans = 0;
	LL tot = 0;
	for (int i = n + 1; i <= 2 * n; i++)
	{
		tot += cost[i];
		if (i > n + 1) tot += a;
		if (tot > t) break;
		ans++;
	}
	tot = 0;
	for (int i = 1; i <= n; i++)
	{
		tot += cost[i];
	}
	int ptr = 1;
	LL c = 0;
	for (int i = n + 1; i <= 2 * n; i++)
	{
		c += cost[i];
		if (i > n + 1) c += a;
		while (ptr <= n && tot + c + (i - ptr)*a > t) tot -= cost[ptr++];
		if (ptr > n) break;
		ans = max(ans, i - ptr + 1);
	}
	return min(ans, n);
}
void refrain()
{
	int r = n + 2;
	int l = n;
	while (r <= 2 * n) cost[r++] = cost[l--];
	memcpy(cost + 1, cost + n + 1, sizeof(LL)*n);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(cost, 0);
	cin >> n >> a >> b >> t;
	string str;
	cin >> str;
	for (int i = 1; i <= n; i++)
	{
		cost[i] = 1;
		if (str[i - 1] == 'w') cost[i] += b;
	}
	memcpy(cost + n + 1, cost + 1, sizeof(LL)*n);
	int ans1 = getans();
	refrain();
	int ans2 = getans();
	cout << max(ans1, ans2) << endl;
	return 0;
}