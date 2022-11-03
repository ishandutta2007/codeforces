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
const int N = 2e5 + 10;
int a[N];
int flag[N];
void output(int n, int key = 0)
{
	flag[key] = 1;
	int tot = 0;
	for (int i = 1; i <= n; i++) tot += flag[i];
	if (tot == n) flag[key] = 0;
	if (key != 0 && flag[key]) printf("2 %d\n", key);
	int s = 1;
	while (flag[s]) s++;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		if (i == s) continue;
		printf("1 %d %d\n", i, s);
	}
	exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v1;
	vector<pair<int, int>> v2;
	vector<pair<int, int>> v0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > 0) v1.emplace_back(a[i], i);
		if (a[i] < 0) v2.emplace_back(a[i], i);
		if (a[i] == 0) v0.emplace_back(a[i], i);
	}
	while (v0.size() > 1)
	{
		flag[v0.back().second] = 1;
		printf("1 %d %d\n", v0.back().second, v0.front().second);
		v0.pop_back();
	}
	sort(v2.begin(), v2.end());
	if (v0.empty())
	{
		if (v2.size() & 1) output(n, v2.back().second);
		else output(n);
	}
	else
	{
		if (v2.size() & 1)
		{
			int x = v2.back().second;
			flag[x] = 1;
			v2.pop_back();
			printf("1 %d %d\n", x, v0.back().second);
		}
		output(n, v0.back().second);
	}
	return 0;
}