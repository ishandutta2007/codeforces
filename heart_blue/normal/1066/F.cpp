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
const int N = 2e5 + 20;
const int MOD = 998244353;
map<int, vector<pair<int, int>>> mc;
LL dis(pair<int, int> &p1, pair<int, int> &p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	//cout << n * 2 << endl;
	//int tot = 1e9;
	//for (int i = 0; i < n; i++)
	//{
	//	cout << tot - i << " 0" << endl;
	//	cout << "0 " << tot - i << endl;
	//}
	//return 0;
	pair<int, int> p1 = { 0,0 }, p2 = { 0,0 };
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		mc[max(x, y)].push_back({ x,y });
	}
	LL ans1 = 0, ans2 = 0;
	for (auto &p : mc)
	{
		auto &v = p.second;
		sort(v.begin(), v.end(), [](pair<int, int> &p1, pair<int, int> &p2) -> bool
		{
			if (p1.first != p2.first) return p1.first < p2.first;
			return p1.second > p2.second;
		});
		LL res1 = INF * INF, res2 = INF * INF;
		for (auto &pp : v)
		{
			res1 = min({ ans1 + dis(p1, pp) + dis(pp, v.back()) + dis(v.back(), v.front()),
				ans2 + dis(p2, pp) + dis(pp, v.back()) + dis(v.back(), v.front()),
				res1 });
			res2 = min({ ans1 + dis(p1, pp) + dis(pp, v.front()) + dis(v.front(), v.back()),
				ans2 + dis(p2, pp) + dis(pp, v.front()) + dis(v.front(), v.back()),
				res2 });
		}
		ans1 = res1;
		ans2 = res2;
		p1 = v.front();
		p2 = v.back();
	}
	printf("%lld\n", min(ans1, ans2));
	return 0;
}