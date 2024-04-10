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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
vector<int> v[N];
map<int, int> mc1, mc2;
int dfs(int x, int fa = 0)
{
	if (mc1.count(x)) return x;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		int ret = dfs(y, x);
		if (ret != 0) return ret;
	}
	return 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		mc1.clear();
		mc2.clear();
		int k1, k2;
		cin >> k1;
		while (k1--)
		{
			int x;
			cin >> x;
			mc1[x] = 1;
		}
		cin >> k2;
		while (k2--)
		{
			int x;
			cin >> x;
			mc2[x] = 1;
		}
		int vb1 = mc2.begin()->first;
		int va1;
		cout << "B " << vb1 << endl;
		cin >> va1;
		int va2 = dfs(va1);
		cout << "A " << va2 << endl;
		int vb2;
		cin >> vb2;
		if (mc2.count(vb2)) cout << "C " << va2 << endl;
		else cout << "C -1" << endl;
	}
	return 0;
}