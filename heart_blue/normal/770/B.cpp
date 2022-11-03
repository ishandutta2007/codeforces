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
int sum(LL x)
{
	int ret = 0;
	while (x)
	{
		ret += x % 10;
		x /= 10;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	cin >> n;
	pair<int, LL> ans = { sum(n),n };
	LL sub = 1, add = 0;
	LL maxv = 1e18;
	while (n >= sub)
	{
		LL o = (n - sub) / sub*sub + add;
		ans = max(ans, { sum(o),o });
		if (sub == maxv) break;
		sub *= 10;
		add = add * 10 + 9;
	}
	cout << ans.second << endl;
	return 0;
}