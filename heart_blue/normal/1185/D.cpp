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
const int N = 3e3 + 10;
int a[N];
void solve(vector<pair<int, int>> vp, int o)
{
	int key = 0;
	if (o != -1)
	{
		key = vp[o].second;
		vp.erase(vp.begin() + o);
	}
	int a = vp[0].first, b = vp[1].first;
	for (int i = 2; i < vp.size(); i++)
	{
		int c = vp[i].first;
		if (c - b != b - a)
		{
			if (key) return;
			key = vp[i].second;
		}
		else
		{
			a = b;
			b = c;
		}
	}
	if (key == 0) key = vp[0].second;
	printf("%d\n", key);
	exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n <= 3)
	{
		puts("1");
		return 0;
	}
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		v.emplace_back(x, i);
	}
	sort(v.begin(), v.end());
	for (int i = -1; i < 2; i++)
	{
		solve(v, i);
	}
	puts("-1");
	return 0;
}