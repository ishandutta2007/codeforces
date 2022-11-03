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
pair<int, int> lx[N], rx[N], ly[N], ry[N];
pair<int, int> combine(pair<int, int> p1, pair<int, int> p2)
{
	return make_pair(max(p1.first, p2.first), min(p1.second, p2.second));
}
bool check(pair<int, int> p1)
{
	return p1.first <= p1.second;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &lx[i].first, &ly[i].first, &lx[i].second, &ly[i].second);
		rx[i] = lx[i];
		ry[i] = ly[i];
	}
	lx[0] = ly[0] = ry[n + 1] = rx[n + 1] = make_pair(-int(INF), int(INF));
	for (int i = 1; i <= n; i++)
	{
		lx[i] = combine(lx[i], lx[i - 1]);
	}
	for (int i = 1; i <= n; i++)
	{
		ly[i] = combine(ly[i], ly[i - 1]);
	}
	for (int i = n; i > 0; i--)
	{
		rx[i] = combine(rx[i], rx[i + 1]);
	}
	for (int i = n; i > 0; i--)
	{
		ry[i] = combine(ry[i], ry[i + 1]);
	}
	for (int i = 1; i <= n; i++)
	{
		auto p1 = combine(lx[i - 1], rx[i + 1]);
		auto p2 = combine(ly[i - 1], ry[i + 1]);
		if (check(p1) && check(p2))
		{
			cout << p1.first << ' ' << p2.first << '\n';
			return 0;
		}
	}
	return 0;
}