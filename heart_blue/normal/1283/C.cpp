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
int f[N];
int deg[N];
int dfs(int x)
{
	if (f[x] == 0) return x;
	else return dfs(f[x]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> f[i];
		deg[f[i]]++;
	}
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			vp.emplace_back(i, dfs(i));
		}
	}
	vp.push_back(vp[0]);
	for (int i = 0; i + 1 < vp.size(); i++)
	{
		f[vp[i].second] = vp[i + 1].first;
	}
	for (int i = 1; i <= n; i++) cout << f[i] << ' ';
	return 0;
}