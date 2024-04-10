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
const int N = 3e5 + 10;
int a[N];
int pos[N];
vector<pair<int, int>> ans;
bool change(int x, int y, int n)
{
	if (abs(x - y) * 2 >= n)
	{
		ans.emplace_back(x, y);
		swap(a[x], a[y]);
		swap(pos[a[x]], pos[a[y]]);
		return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		int v[3] = { i, 1,n };
		int o = 0;
		while (a[i] != i)
		{
			if (change(pos[i], v[o], n)) o = 0;
			else o++;
		}
	}
	printf("%d\n", ans.size());
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}