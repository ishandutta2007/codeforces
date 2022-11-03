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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int n, m, r, k;
priority_queue<LL, vector<LL>, greater<LL>> pq;
bool add(int x, int y)
{
	int lx = max(1, x - r + 1);
	int ly = max(1, y - r + 1);
	int rx = x + r - 1;
	int ry = y + r - 1;
	if (rx > n) rx = x - (rx - n);
	else rx = x;
	if (ry > m) ry = y - (ry - m);
	else ry = y;
	LL tot = 1LL * (rx - lx + 1) * (ry - ly + 1);
	if (pq.size() == k && pq.top() >= tot)
		return false;
	pq.push(tot);
	if (pq.size() > k)
		pq.pop();
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &r, &k);
	for (int i = n / 2; i >= 1; i--)
	{
		for (int j = m / 2; j >= 1; j--)
		{
			if (!add(i, j))
				break;
		}
		for (int j = m / 2 + 1; j <= m; j++)
		{
			if (!add(i, j))
				break;
		}
	}
	for (int i = n / 2 + 1; i <= n; i++)
	{
		for (int j = m / 2; j >= 1; j--)
		{
			if (!add(i, j))
				break;
		}
		for (int j = m / 2 + 1; j <= m; j++)
		{
			if (!add(i, j))
				break;
		}
	}
	LL tot = 0;
	while (!pq.empty())
	{
		tot += pq.top();
		pq.pop();
	}
	printf("%.15f\n", 1.0 * tot / (n - r + 1) / (m - r + 1));
	return 0;
}