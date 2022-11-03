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
const int N = 1e5 + 10;
vector<int> v;
LL getans(LL o)
{
	map<LL, int> m;
	LL ans = 0;
	LL sum = 0;
	m[0] = 1;
	for (auto &x : v)
	{
		sum += x;
		if (m.count(sum - o))
			ans += m[sum - o];
		m[sum]++;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	v.resize(n);
	LL tot = 0;
	for (auto &x : v) cin >> x, tot += abs(x);
	LL cur = 1;
	LL ans = 0;
	map<LL, int> mc;
	while (abs(cur) <= tot)
	{
		if (mc.count(cur)) break;
		mc[cur] = 1;
		ans += getans(cur);
		cur *= m;
	}
	cout << ans << endl;
	return 0;
}