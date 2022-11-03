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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL ts, tf, t;
	cin >> ts >> tf >> t;
	map<LL, LL> ms;
	int n;
	cin >> n;
	while (n--)
	{
		LL x;
		cin >> x;
		ms[x] += t;
	}
	LL cur = ts;
	ms[tf - t + 1] = t;
	pair<LL, LL> ans = { INF*INF,0 };
	for (auto &p : ms)
	{
		if (p.first > 0)
		{
			if (cur + t <= tf)
				ans = min(ans, { max(0LL,cur - (p.first - 1)),p.first - 1 });
		}
		cur = max(cur, p.first) + p.second;
	}
	cout << ans.second << endl;
	return 0;
}