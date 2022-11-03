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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
vector<int> v[N];
vector<int> v2[N];
int sons[N];
int flag[N];
vector<int> ans;
void dfs2(int x)
{
	ans.push_back(x);
	for (auto &y : v2[x]) dfs2(y);
}
bool dfs(int x, int p = 0)
{
	if (p) sons[x] = 1;
	for (auto &y : v[x])
	{
		dfs(y, x);
		sons[x]++;
	}
	flag[x] = sons[x] & 1;
	if (flag[x] == 0)
	{
		ans.push_back(x);
		for (auto &y : v2[x])
		{
			dfs2(y);
		}
		sons[p]--;
	}
	else
	{
		if (p == 0) return false;
		else v2[p].push_back(x);
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int rt = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
		
	}
	if (dfs(v[0].back()))
	{
		puts("YES");
		for (auto &x : ans) printf("%d\n", x);
	}
	else puts("NO");
	return 0;
}