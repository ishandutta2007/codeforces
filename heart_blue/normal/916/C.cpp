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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n == 2)
	{
		cout << 2 << ' ' << 2 << endl;
		cout << 1 << ' ' << 2 << ' ' << 2 << endl;
		return 0;
	}
	int inf = 100003;
	map<pair<int, int>, int> mp;
	mp[{1, 2}] = 1;
	mp[{2, n}] = 1;
	int cnt = 2;
	for (int i = 3; i < n - 1; i++) mp[{1, i}] = 1, cnt++;
	if (n > 3) mp[{1, n - 1}] = inf - cnt++;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (mp.count({ i,j })) continue;
			if (cnt < m)
			{
				mp[{i, j}] = inf;
				cnt++;
			}
			else break;
		}
		if (cnt == m) break;
	}
	printf("%d %d\n", 2, n == 3?2: inf);
	for (auto &p : mp)
	{
		int x, y;
		tie(x, y) = p.first;
		printf("%d %d %d\n", x, y, p.second);
	}
	return 0;
}