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
const int N = 5e5 + 10;
int check(pair<int, int> &p1, pair<int, int> &p2)
{
	if (p1 == p2) return -1;
	else if (p1.first == p2.first || p1.first == p2.second) return p1.first;
	else if (p1.second == p2.first || p1.second == p2.second) return p1.second;
	else return -1;
}
int check(vector<pair<int, int>> &vp1, vector<pair<int, int>> &vp2)
{
	map<int, int> ret;
	for (auto &p1 : vp1)
	{
		map<int, int> mc;
		for (auto &p2 : vp2)
		{
			mc[check(p1, p2)] = 1;
		}
		mc.erase(-1);
		if (mc.size() > 1)
		{
			puts("-1");
			exit(0);
		}
		if (mc.size() == 0) continue;
		ret[mc.begin()->first] = 1;
	}
	if (ret.size() == 0)
	{
		puts("-1");
		exit(0);
	}
	if (ret.size() == 1) return ret.begin()->first;
	else return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> vp1(n), vp2(m);
	for (auto &p : vp1)
	{
		cin >> p.first >> p.second;
		if (p.first > p.second) swap(p.first, p.second);
	}
	for (auto &p : vp2)
	{
		cin >> p.first >> p.second;
		if (p.first > p.second) swap(p.first, p.second);
	}
	printf("%d\n", check(vp1, vp2)&(check(vp2, vp1)));
	return 0;
}