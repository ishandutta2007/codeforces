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
const int N = 3e5 + 10;
vector<pair<int, int>> vp;
int dis(pair<int, int>& p1, pair<int, int>& p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
void refrain()
{
	int pos = min_element(vp.begin(), vp.end()) - vp.begin();
	vector<pair<int, int>> ret;
	for (int i = pos; i < vp.size(); i++) ret.push_back(vp[i]);
	for (int i = 0; i < pos; i++) ret.push_back(vp[i]);
	vp.swap(ret);
}
int ans[N];
void solve(int n)
{
	
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vp.resize(n);
	int max1 = -INF, min1 = INF;
	int max2 = -INF, min2 = INF;
	for (auto& [a, b] : vp)
	{
		scanf("%d%d", &a, &b);
		max1 = max(max1, a);
		max2 = max(max2, b);
		min1 = min(min1, a);
		min2 = min(min2, b);
	}
	ans[4] = (max1 - min1) * 2 + (max2 - min2) * 2;
	vector<pair<int, int>> key;
	for (auto& [a, b] : vp)
	{
		if (a == max1 || a == min1 || b == max2 || b == min2)
			key.emplace_back(a, b);
	}
	for (auto& p1 : key)
	{
		for (auto& p2 : key)
		{
			for (auto& p3 : vp)
			{
				ans[3] = max(ans[3], dis(p1, p2) + dis(p2, p3) + dis(p1, p3));
			}
		}
	}
	for (int i = 3; i <= n; i++)
	{
		ans[i] = max(ans[i], ans[i - 1]);
		printf("%d ", ans[i]);
	}
	return 0;
}