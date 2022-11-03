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
const int N = 2e5 + 10;
map<LL, int> flag;
LL a[60];
vector<LL> key;
vector<tuple<LL, LL, int>> vp;
bool add(LL x)
{
	LL o = x;
	for (int i = 50; i >= 0; i--)
	{
		if (x >> i & 1)
		{
			if (a[i] == 0)
			{
				a[i] = x;
				key.push_back(o);
				return true;
			}
			else
				x ^= a[i];
		}
	}
	return false;
}
bool check(LL x)
{
	LL o = x;
	for (int i = 50; i >= 0; i--)
	{
		if (x >> i & 1)
		{
			if (a[i] == 0)
			{
				a[i] = x;
				return i == 0;
			}
			else
			{
				if (!flag.count(x ^ a[i]))
				{
					flag[x ^ a[i]] = 1;
					vp.emplace_back(x, a[i], 0);
				}
				x ^= a[i];
			}
		}
	}
	return false;
}
void refrain(LL x, LL maxv)
{
	while (x + x < maxv)
	{
		vp.emplace_back(x, x, 1);
		x += x;
		flag[x] = 1;
		add(x);
	}
}
void build(vector<LL>& v)
{
	LL cur = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		vp.emplace_back(cur, v[i], 1);
		cur += v[i];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	std::random_device rd;
	std::mt19937 mt(rd());
	vector<LL> v;
	LL x;
	scanf("%lld", &x);
	LL maxv = 1LL << 50;
	refrain(x, maxv);
	flag[x] = 1;
	int cnt = 1;

	for (int i = 1; i < (1 << 22); i++)
	{
		if (add(1LL * i * x))
		{
			vector<LL> v;
			for (int o = 0; i >> o; o++)
			{
				if (i >> o & 1)
					v.emplace_back(x << o);
			}
			build(v);
		}
	}
	MEM(a, 0);
	for (auto& x : key)
	{
		if (check(x))
			break;
	}
	printf("%d\n", vp.size());
	for (auto& p : vp)
	{
		LL x, y;
		int o;
		tie(x, y, o) = p;
		printf("%lld %c %lld\n", x, "^+"[o], y);
	}
	return 0;
}