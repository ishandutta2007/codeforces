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
#define MEM(a,b) memset((a),(vp),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int flag[N];
pair<int, int> vp[N];
int l, r;
void refrain(int &l1, int &r1, int l2, int r2)
{
	l1 = max(l1, l2);
	r1 = min(r1, r2);
}
int check(int n)
{
	l = 0, r = INF;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		refrain(l, r, vp[i].first, vp[i].second);
	}
	return r - l;
}
int check(int n, int x, int o)
{
	int key = 0;
	int pos = 0;
	for (int i = 1; i <= n; i++)
	{
		if (o == 0)
		{
			if (vp[i].first == x)
			{
				if (key == 0) pos = i, key = vp[i].second;
				if (vp[i].second < key)
				{
					pos = i;
					key = vp[i].second;
				}
			}
		}
		else
		{
			if (vp[i].second == x)
			{
				if (key == 0) pos = i, key = vp[i].first;
				if (vp[i].first > key)
				{
					pos = i;
					key = vp[i].first;
				}
			}
		}
	}
	flag[pos] = 1;
	int ret = check(n);
	flag[pos] = 0;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &vp[i].first, &vp[i].second);
		mc[vp[i].first]++;
		mc[vp[i].second] += 0;
		mc[vp[i].second + 1]--;
	}
	int ans = 0;
	check(n);
	vector<int> v;
	if (ans >= 0)
	{
		v.push_back(l);
		v.push_back(r);
	}
	int sum = 0;
	for (auto &p : mc)
	{
		sum += p.second;
		if (sum == n - 1)
		{
			v.push_back(p.first);
		}
	}
	int cnt = 20;
	for (auto &x : v)
	{
		int res = max(check(n, x, 0), check(n, x, 1));
		ans = max(ans, res);
		if (cnt-- == 0) break;
	}
	printf("%d\n", ans);
	return 0;
}