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
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
vector<pair<int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, s;
	cin >> n >> s;
	LL tot = 0;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x, a, b;
		cin >> x >> a >> b;
		ans += 1LL * x*a;
		tot += x;
		vp.push_back({ b - a,x });
	}
	sort(vp.rbegin(), vp.rend());
	LL cost = (tot - 1) / s + 1;
	LL maxv = 0;
	LL sum = 0;
	LL pre = 0;
	for (auto &p : vp)
	{
		tot -= p.second;
		LL costa = (sum - 1 + s) / s;
		LL costb = (tot - 1 + s) / s;
		LL rest = (cost - costa - costb)*s;
		LL resta = costa * s - sum;
		LL restb = costb * s - tot;
		sum += p.second;
		if (rest >= 0 && rest + resta + restb >= p.second)
		{
			auto check = [](LL rest, LL resta, LL restb, LL cnt, LL p1, LL p2)->LL
			{
				LL ret = 0;
				LL o1 = min(resta, cnt);
				ret += o1 * p1;
				cnt -= o1;
				o1 = min(rest, cnt);
				ret += o1 * p1;
				cnt -= o1;
				o1 = min(restb, cnt);
				return ret += o1 * p2;

			};
			maxv = max({ maxv,
				pre + check(rest,resta,restb,p.second,p.first,0),
				pre + check(rest,restb,resta,p.second,0,p.first) });
		}
		pre += 1LL * p.first*p.second;

	}
	printf("%lld\n", ans + maxv);

	return 0;
}