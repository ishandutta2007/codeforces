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
int flag[N];
vector<int> v[N];
LL cnt[2];
bool dfs(int x, int o = 0)
{
	if (flag[x] != -1) return o == flag[x];
	flag[x] = o;
	cnt[o]++;
	for (auto &y : v[x])
	{
		if (!dfs(y, o ^ 1)) return false;
	}
	return true;
}
LL sum(LL x)
{
	return x*(x - 1) / 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	MEM(flag, -1);
	LL c1 = 0, c2 = 0;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] != -1) continue;
		cnt[0] = cnt[1] = 0;
		if (!dfs(i))
		{
			cout << "0 1" << endl;
			return 0;
		}
		ans += sum(cnt[0]) + sum(cnt[1]);
		if (cnt[0] + cnt[1] == 1) c1++;
		else if (cnt[0] + cnt[1] == 2) c2++;
	}
	if (ans > 0)
	{
		cout << 1 << ' ' << ans << endl;
		return 0;
	}
	if (c2 > 0)
	{
		cout << 2 << ' ' << sum(c2) * 4 + c2*c1 << endl;
		return 0;
	}
	cout << 3 << ' ' << c1*(c1 - 1)*(c1 - 2) / 6 << endl;
	return 0;
}