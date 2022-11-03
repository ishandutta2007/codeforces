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
const int N = 2e5 + 10;
int a[N];
map<int, vector<pair<int, int>>> mv;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<int, int>> ans;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = i; j <= n; j++)
		{
			sum += a[j];
			mv[sum].push_back({ j, i });
		}
	}
	for (auto &p : mv)
	{
		vector<pair<int, int>> &vp = p.second;
		if (vp.size() <= ans.size()) continue;
		sort(vp.begin(), vp.end());
		int cur = 0;
		vector<pair<int, int>> tmp;
		for (auto &p : vp)
		{
			int l, r;
			tie(r, l) = p;
			if (l > cur)
			{
				tmp.emplace_back(l, r);
				cur = r;
			}
		}
		if (tmp.size() > ans.size()) ans = tmp;
	}
	printf("%d\n", ans.size());
	for (auto &p : ans)
	{
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}