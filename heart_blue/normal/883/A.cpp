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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m, a, d;
	cin >> n >> m >> a >> d;
	LL nexta = a;
	LL A = (d / a + 1)*a;
	LL cur = 0;
	LL ans = 0;
	auto check = [&](LL x) -> LL
	{
		LL tot = min(n*a, x / a*a);
		LL ret = 0;
		if (tot >= nexta)
		{
			LL o = (tot - nexta) / A + 1;
			ret += o;
			cur = nexta + (tot - nexta) / A*A + d + 1;
			nexta += o*A;
		}
		if (cur <= x)
		{
			ret += 1;
			cur = x + d + 1;
			nexta = (cur + a - 1) / a*a;
		}
		return ret;
	};
	while (m--)
	{
		LL x;
		cin >> x;
		ans += check(x);
	}
	ans += check(n*a);
	cout << ans << endl;
	return 0;
}