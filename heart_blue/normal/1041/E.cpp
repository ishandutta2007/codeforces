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
int sz[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (b != n) puts("NO"), exit(0);
		sz[a]++;
	}
	vector<int> v;
	vector<pair<int, int>> ans;
	for (int i = 1; i < n; i++)
	{
		v.push_back(i);
		if (sz[i] == 0) continue;
		if (sz[i] > v.size())
		{
			puts("NO");
			return 0;
		}
		v.pop_back();
		int x = i;
		while (--sz[i])
		{
			int y = v.back();
			v.pop_back();
			ans.emplace_back(x, y);
			x = y;
		}
		ans.emplace_back(x, n);
	}
	if (!v.empty())
		puts("NO"), exit(0);
	puts("YES");
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}