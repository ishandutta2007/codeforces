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
const int N = 3e5 + 10;
pair<int, int> ans[N];
int a[N];
int b[N];
int res[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n + m; i++) cin >> a[i];
	for (int i = 1; i <= n + m; i++) cin >> b[i];
	a[n + m + 1] = INF * 2;
	a[0] = -INF;
	b[0] = b[n + m + 1] = 1;
	MEM(ans, 0x3f);
	int pre;
	pre = 0;
	for (int i = 0; i <= n + m; i++)
	{
		if (b[i]) pre = i;
		else ans[i] = min(ans[i], make_pair(a[i] - a[pre], pre));
	}
	for (int i = n + m + 1; i >= 0; i--)
	{
		if (b[i]) pre = i;
		else ans[i] = min(ans[i], make_pair(a[pre] - a[i], pre));
	}
	for (int i = 1; i <= n + m; i++)
	{
		if (b[i] == 0)
			res[ans[i].second]++;
	}
	for (int i = 1; i <= n + m; i++)
	{
		if (b[i])
			cout << res[i] << ' ';
	}
	return 0;
}