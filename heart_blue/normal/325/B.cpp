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
inline LL multy(LL a, LL b)
{
	if (a == 0 || b == 0) return 0;
	if (a > LLONG_MAX / b) return LLONG_MAX;
	else return a * b;
}
inline LL add(LL a, LL b)
{
	if (a > LLONG_MAX - b) return LLONG_MAX;
	else return a + b;
}
LL check(LL delta, LL n)
{
	LL l = 1, r = INF * INF;
	LL ret = 0;
	n *= 2;
	delta *= 2;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		if (add(multy(delta, mid), multy(mid, mid - 1)) >= n) ret = mid, r = mid - 1;
		else l = mid + 1;
	}
	if (add(multy(delta, ret), multy(ret, ret - 1)) == n && ret % 2 != 0) return ret;
	else return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<LL> ans;
	LL n;
	cin >> n;
	ans.push_back(check(0, n));
	LL cur = 0;
	for (int o = 0; n >> o; o++)
	{
		cur = cur * 2 + 1;
		ans.push_back(check(cur, n) * (cur + 1));
	}
	sort(ans.begin(), ans.end());
	int flag = 0;
	for (auto& x : ans)
	{
		if (x == 0) continue;
		printf("%lld\n", x);
		flag = 1;
	}
	if (flag == 0) puts("-1");
	return 0;
}