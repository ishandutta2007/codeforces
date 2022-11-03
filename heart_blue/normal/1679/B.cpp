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
const int N = 2e5 + 10;
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	LL sum = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum += a[i];
	vector<int> v;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	int cur = 0;
	while (q--)
	{
		int op, x, y;
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d%d", &x, &y);
			if (flag[x] != cur)
				flag[x] = cur, a[x] = cur;
			v.push_back(x);
			sum += y - a[x];
			a[x] = y;
		}
		else
		{
			scanf("%d", &x);
			sum = 1LL * x * n;
			cur = x;
			for (auto& pos : v)
				a[pos] = x;
			v.clear();
		}
		printf("%lld\n", sum);
	}
	return 0;
}