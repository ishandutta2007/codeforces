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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL k;
	cin >> n >> k;
	set<pair<int, int>> sp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		sp.emplace(x, i);
	}
	int cur = 0;
	while (!sp.empty())
	{
		int x = sp.begin()->first;
		if ((x - cur) * 1LL * sp.size() <= k)
		{
			k -= (x - cur) * 1LL * sp.size();
			while (!sp.empty())
			{
				if (sp.begin()->first == x)
					sp.erase(sp.begin());
				else
					break;
			}
			cur = x;
			continue;
		}
		x = k / sp.size() + cur;
		k %= sp.size();
		vector<pair<int, int>> vp;
		for (auto p : sp)
		{
			p.first -= x;
			vp.emplace_back(p.second, p.first);
		}
		sort(vp.begin(), vp.end());
		queue<pair<int, int>> q;
		for (auto& p : vp)
			q.push(p);
		while (k--)
		{
			auto p = q.front();
			q.pop();
			if (p.second > 1)
				q.push(p);
		}
		while (!q.empty())
		{
			printf("%d ", q.front().first);
			q.pop();
		}
		return 0;
	}
	if (k) puts("-1");
	return 0;
}