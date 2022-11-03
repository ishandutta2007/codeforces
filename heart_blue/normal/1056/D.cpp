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
int sum[N];
vector<int> v[N];
void dfs(int x)
{
	if (v[x].empty())
	{
		sum[x] = 1;
		return;
	}
	for (auto& y : v[x])
	{
		dfs(y);
		sum[x] += sum[y];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	dfs(1);
	sort(sum + 1, sum + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", sum[i]);
	}
	return 0;
}