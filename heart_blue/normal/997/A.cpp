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


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL x, y;
	cin >> n >> x >> y;
	string str;
	cin >> str;
	str += '1';
	int cnt0 = 0;
	int cur = 0;
	for (auto &c : str)
	{
		if (c == '0') cur++;
		else
		{
			if (cur > 0) cnt0++;
			cur = 0;
		}
	}
	LL ans = INF * INF;
	if (cnt0 == 0) ans = 0;
	for (int i = 0; i < cnt0; i++)
	{
		ans = min(ans, i*x + (cnt0 - i)*y);
	}
	printf("%lld\n", ans);
	return 0;
}