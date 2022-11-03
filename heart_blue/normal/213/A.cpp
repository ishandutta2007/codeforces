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
const int N = 4e3 + 10;
vector<int> v[N];
int c[N];
int deg[N];
int n;
int solve(int o)
{
	MEM(deg, 0);
	for (int i = 1; i <= n; i++)
	{
		for (auto &x : v[i])
			deg[x]++;
	}
	queue<int> q[4];
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
			q[c[i]].push(i);
	}
	int ans = n;
	while (q[1].size() + q[2].size() + q[3].size() > 0)
	{
		if (q[o].empty())
		{
			o++;
			if (o == 4) o = 1;
			ans++;
			continue;
		}
		int x = q[o].front();
		q[o].pop();
		for (auto &y : v[x])
		{
			if (deg[y]-- == 1)
				q[c[y]].push(y);
		}
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		while (m--)
		{
			int x;
			cin >> x;
			v[x].push_back(i);
		}
	}
	cout << min(solve(1), min(solve(2), solve(3))) << endl;
	return 0;
}