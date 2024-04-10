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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int dis[2][N];
char str[2][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s%s", str[0], str[1]);
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	for (int o = 0; o < 2; o++)
	{
		for (int i = 0; i < n; i++)
		{
			dis[o][i] = i + 1;
			if (str[o][i] == 'X') dis[o][i] = 0;
		}
	}
	dis[0][0] = 0;
	while (!q.empty())
	{
		int o, x;
		tie(o, x) = q.front();
		q.pop();
		if (x == n - 1)
		{
			cout << "YES" << endl;
			return 0;
		}
		if (dis[o][x + 1] > dis[o][x] + 1)
		{
			dis[o][x + 1] = dis[o][x] + 1;
			q.push({ o,x + 1 });
		}
		if (x > 0 && dis[o][x - 1] > dis[o][x] + 1)
		{
			dis[o][x - 1] = dis[o][x] + 1;
			q.push({ o,x - 1 });
		}
		if (x + k > n - 1)
		{
			cout << "YES" << endl;
			return 0;
		}
		if (dis[o ^ 1][x + k] > dis[o][x] + 1)
		{
			dis[o ^ 1][x + k] = dis[o][x] + 1;
			q.push({ o ^ 1,x + k });
		}
	}
	cout << "NO" << endl;
	return 0;
}