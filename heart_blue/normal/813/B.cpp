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
const int N = 2e2 + 10;
vector<LL> v1;
vector<LL> v2;
void add(vector<LL> &v, LL x)
{
	LL o = 1;
	while (1)
	{
		v.push_back(o);
		if (o > INF*INF / x) break;
		o *= x;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL x, y, l, r;
	cin >> x >> y >> l >> r;
	add(v1, x);
	add(v2, y);
	vector<LL> v;
	for (auto &x : v1)
	{
		for (auto &y : v2)
		{
			if (x + y >= INF*INF) continue;
			v.push_back(x + y);
		}
	}
	LL pre = l;
	v.push_back(l - 1);
	v.push_back(r + 1);
	sort(v.begin(), v.end());
	LL ans = 0;
	for (auto &x : v)
	{
		if (x < l) continue;
		if (x > r) x = r + 1;
		ans = max(ans, x - pre);
		pre = x + 1;
	}
	cout << ans << endl;
	return 0;
}