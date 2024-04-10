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
const int N = 4e5 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	for (int i = 1; i <= m; i++)
	{
		if (v[i].empty()) continue;
		sort(v[i].rbegin(), v[i].rend());
	}
	int tot = v[1].size();
	LL ans = INF * INF;
	for (int o = max(tot, 1); o <= n; o++)
	{
		LL sum = 0;
		vector<int> tmp;
		int cur = tot;
		for (int i = 2; i <= m; i++)
		{
			for (int j = o - 1; j < v[i].size(); j++) cur++, sum += v[i][j];
			for (int j = 0; j < min(o - 1, int(v[i].size())); j++) tmp.push_back(v[i][j]);
		}
		if (!tmp.empty()) sort(tmp.rbegin(), tmp.rend());
		while (cur < o)
		{
			cur++;
			sum += tmp.back();
			tmp.pop_back();
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;

	return 0;
}