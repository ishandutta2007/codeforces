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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
int a[N];
int lsum[N];
int rsum[N];
vector<int> v[N];
int solve(vector<int>& vp)
{
	int maxv = 0;
	int ret = 0;
	for (auto& x : vp)
	{
		maxv = max(lsum[x - 1], maxv) + 1;
		ret = max(ret, maxv + rsum[x + 1]);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		v[a[i]].push_back(i);
		lsum[i] = lsum[i - 1] + (a[i] == c);
	}
	for (int i = n; i >= 1; i--)
	{
		rsum[i] = rsum[i + 1] + (a[i] == c);
	}
	int ans = v[c].size();
	for (int i = 1; i < N; i++)
	{
		if (v[i].empty()) continue;
		ans = max(ans, solve(v[i]));
	}
	printf("%d\n", ans);
	return 0;
}