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
bool check(vector<int> v, int pos)
{
	int n = v.size() / 2;
	int y = v[pos];
	v.erase(v.begin() + pos);
	int x = y + v.back();
	v.push_back(y);
	map<int, int> ms;
	for (auto& x : v)
		ms[x]++;
	reverse(v.begin(), v.end());
	vector<pair<int, int>> ans;
	int key = x;
	for (auto& y : v)
	{
		if (ms[y] == 0) continue;
		ms[y]--;
		if (ms[x - y] == 0) return false;
		ms[x - y]--;
		ans.emplace_back(x - y, y);
		x = max(y, x - y);
	}
	puts("YES");
	printf("%d\n", key);
	for (auto [x, y] : ans)
		printf("%d %d\n", x, y);
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<int> v(2 * n);
		for (auto& x : v)
			scanf("%d", &x);
		sort(v.begin(), v.end());
		int flag = 0;
		for (int i = 0; i + 1 < v.size(); i++)
		{
			if (check(v, i))
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
			puts("NO");
	}
	return 0;
}