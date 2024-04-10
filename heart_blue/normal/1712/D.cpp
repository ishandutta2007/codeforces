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
const int N = 2e5 + 10;
bool check(vector<int> v, int k, int o)
{
	int cnt = 0;
	for (auto& x : v)
	{
		if (x * 2 >= o) continue;
		x = 1e9;
		cnt++;
	}
	int rest = 2;
	for (int i = 0; i + 1 < v.size(); i++)
	{
		if (v[i] >= o && v[i + 1] >= o) rest = 0;
		else if (v[i] >= o || v[i + 1] >= o) rest = min(rest, 1);
	}
	cnt += rest;
	return cnt <= k;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		int ans = 1e9;
		int l = 1, r = 1e9;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (check(v, k, mid)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}