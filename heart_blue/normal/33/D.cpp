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
const int N = 1e3 + 10;
bitset<N> b[N];
pair<int, int> a[N];
LL dis(pair<int, int>& p1, pair<int, int>& p2)
{
	LL dx = p1.first - p2.first;
	LL dy = p1.second - p2.second;
	return dx * dx + dy * dy;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
	for (int i = 0; i < m; i++)
	{
		int r, x, y;
		scanf("%d%d%d", &r, &x, &y);
		pair<int, int> p = { x,y };
		for (int j = 0; j < n; j++)
		{
			if (dis(a[j], p) <= 1LL * r * r)
				b[j][i] = 1;
		}
	}
	while (k--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		printf("%d\n", (b[x] ^ b[y]).count());
	}
	return 0;
}