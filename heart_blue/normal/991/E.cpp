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
int cnt[10];
LL fact[20];
LL ans = 0;
void dfs(int cur, int x, int tot, LL div)
{
	if (cur == 10)
	{
		ans += fact[tot] / div;
		return;
	}
	if (cnt[cur] == 0)
	{
		dfs(cur + 1, x, tot, div);
	}
	for (int i = 1 - (cur == x); i <= cnt[cur] - (cur == x); i++)
	{
		dfs(cur + 1, x, tot + i, div*fact[i]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fact[0] = 1;
	for (int i = 1; i < 20; i++) fact[i] = i * fact[i - 1];
	string str;
	cin >> str;
	for (auto &c : str) cnt[c - '0']++;
	for (int i = 1; i < 10; i++)
	{
		if (cnt[i])
			dfs(0, i, 0, 1);
	}
	cout << ans << endl;
	return 0;
}