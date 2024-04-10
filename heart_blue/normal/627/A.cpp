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
LL ans = 0;
void dfs(LL sum, LL xorsum, int cnt = 0)
{
	if ((sum & 1) != (xorsum&1)) return;
	if (sum == 0 && xorsum == 0)
	{
		ans += 1LL << cnt;
		return;
	}
	if (sum & 1)
	{
		dfs(sum >> 1, xorsum >> 1, cnt + 1);
	}
	else
	{
		dfs(sum >> 1, xorsum >> 1, cnt);
		if (sum >= 2) dfs((sum - 2) >> 1, xorsum >> 1, cnt);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL sum, xorsum;
	cin >> sum >> xorsum;
	ans = 0;
	dfs(sum, xorsum);
	if (sum == xorsum) ans -= 2;
	cout << ans << endl;
	return 0;
}