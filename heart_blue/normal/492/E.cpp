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
int key[N];
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, dx, dy;
	scanf("%d%d%d%d", &n, &m, &dx, &dy);
	for (int i = 0; i < n; i++)
	{
		key[1LL * i * dx % n] = i;
	}
	int id = 0;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int rest = key[(n - x) % n];
		int o = (y + 1LL * dy * rest) % n;
		cnt[o]++;
		if (cnt[id] < cnt[o])
			id = o;
	}
	printf("%d %d\n", 0, id);
	return 0;
}