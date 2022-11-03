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
const int N = 5e3 + 10;
int a[N];
int pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	set<int> s;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) s.emplace(i);
	int cur = 1;
	while (m--)
	{
		int sz;
		cin >> sz;
		while (sz--)
		{
			int x;
			cin >> x;
			a[x] = cur;
			cur++;
			s.erase(x);
		}
	}
	int zero = *s.begin();
	vector<pair<int, int>> ans;
	auto moveto = [&](int x)
	{
		if (x == zero) return;
		ans.emplace_back(x, zero);
		a[zero] = a[x];
		a[x] = 0;
		zero = x;
	};
	while (1)
	{
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0) continue;
			if (a[i] == i) continue;
			moveto(a[i]);
			moveto(i);
			flag = 1;
		}
		if (flag == 0) break;
	}
	printf("%d\n", ans.size());
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);

		return 0;
}