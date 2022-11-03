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
const int N = 3e3 + 10;
vector<pair<int, int>> ans;
void add(int l, int r)
{
	if (l > r) return;
	if (!ans.empty() && ans.back().second == l) ans.back().second = r;
	else ans.push_back({ l, r });
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> ms;
	int n, k;
	scanf("%d %d", &n, &k);
	while (n--)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		ms[l * 2]++;
		ms[r * 2 + 1]--;
	}
	int tot = 0;
	int pre = -INF;
	for (auto &p : ms)
	{
		if (tot >= k)
		{
			add(pre, p.first);
		}
		tot += p.second;
		pre = p.first;
	}
	printf("%d\n", ans.size());
	for (auto &p : ans)
	{
		printf("%d %d\n", p.first >> 1, p.second >> 1);
	}
	return 0;
}