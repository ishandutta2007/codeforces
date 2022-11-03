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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
map<int, int> cnt, mc;
int a[N];
void add(int x, int val)
{
	if (cnt[x] == 1)
	{
		mc.erase(x);
	}
	cnt[x] += val;
	if (cnt[x] == 1)
	{
		mc[x] = 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		add(a[i], 1);
		if (i > k)
		{
			add(a[i - k], -1);
		}
		if (i >= k)
		{
			if (mc.empty()) puts("Nothing");
			else printf("%d\n", mc.rbegin()->first);
		}
	}
	return 0;
}