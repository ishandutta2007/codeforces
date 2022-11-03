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
const int N = 1e2 + 10;
int a[N][N];
vector<int> solve(int o1, int o2, int m)
{
	vector<pair<int, int>> vp;
	for (int i = 1; i <= m; i++)
	{
		vp.emplace_back(a[i][o1] - a[i][o2], i);
	}
	sort(vp.rbegin(), vp.rend());
	int sum = 0;
	vector<int> ret;
	for (auto& p : vp)
	{
		sum += p.first;
		if (sum < 0) ret.push_back(p.second);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	vector<int> ans;
	for (int i = 1; i <= m; i++) ans.push_back(i);
	for (int i = 1; i < n; i++)
	{
		auto ret = solve(i, n, m);
		if (ans.size() > ret.size())
			ans = ret;
	}
	cout << ans.size() << endl;
	for (auto& x : ans) cout << x << ' ';
	return 0;
}