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
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
int a[N];
int check(int o)
{
	if (o & 1) return a[o] < a[o - 1] && a[o] < a[o + 1];
	else return a[o] > a[o - 1] && a[o] > a[o + 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<int> key;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	a[0] = INF;
	if (n & 1) a[n + 1] = INF;
	else a[n + 1] = -INF;
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		if (!check(i))
		{
			key.push_back(i);
			mc[i] = 1;
		}
	}
	if (key.size() > 10)
	{
		puts("0");
		return 0;
	}
	int ans = 0;
	
	for (auto &x : key)
	{
		for (int i = 1; i <= n; i++)
		{
			if (mc.count(i) && i <= x) continue;
			swap(a[x], a[i]);
			int flag = check(i);
			for (auto &x : key)
				flag &= check(x);
			swap(a[x], a[i]);
			ans += flag;
		}
	}
	printf("%d\n", ans);
	return 0;
}