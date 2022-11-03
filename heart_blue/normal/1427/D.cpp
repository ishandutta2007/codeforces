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
const int N = 3e5 + 10;
void refrain(vector<pair<int, int>>& vp)
{
	vector<pair<int, int>> ret;
	for (auto& p : vp)
	{
		if (!ret.empty() && ret.back().second + 1 == p.first)
			ret.back().second = p.second;
		else
			ret.push_back(p);
	}
	vp = ret;
}
bool check(vector<int>& v)
{
	for (int i = 1; i < v.size(); i++)
		if (v[i - 1] > v[i]) return false;
	return true;
}
int cal(vector<pair<int, int>>& vp, int l, int r)
{
	int ret = 0;
	for (int i = l; i <= r; i++)
	{
		ret += vp[i].second - vp[i].first + 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		v.emplace_back(x, x);
	}
	vector<vector<int>> ans;
	refrain(v);
	while (v.size() > 1)
	{
		int x = -1, y = -1;
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				if (v[i].first == v[j].second + 1)
				{
					x = i, y = j;
					break;
				}
			}
			if (x != -1) break;
		}
		vector<int> ret;
		vector<pair<int, int>> vp;
		if (x > 0) ret.push_back(cal(v, 0, x - 1)), vp.emplace_back(0, x - 1);
		ret.push_back(cal(v, x, x)), vp.emplace_back(x, x);
		ret.push_back(cal(v, x + 1, y)), vp.emplace_back(x + 1, y);
		if (y + 1 < v.size()) ret.push_back(cal(v, y + 1, v.size() - 1)), vp.emplace_back(y + 1, v.size() - 1);
		ans.push_back(ret);
		auto tmp = v;
		reverse(vp.begin(), vp.end());
		v.clear();
		for (auto& p : vp)
		{
			int l, r;
			tie(l, r) = p;
			for (int i = l; i <= r; i++)
				v.push_back(tmp[i]);
		}
		refrain(v);
	}
	printf("%d\n", ans.size());
	for (auto& v : ans)
	{
		printf("%d", v.size());
		for (auto& x : v)
			printf(" %d", x);
		puts("");
	}
	return 0;
}