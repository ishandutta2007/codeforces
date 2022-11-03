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
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	int o = 1;
	LL ans = 0;
	LL key = 0;
	int pre = 0;
	for (int i = 0; i < str.length(); i++)
	{
		LL cur = 1LL * o * (str[i] - '0') % INF;
		int r = str.length() - i - 1;
		LL sum = 1LL * r * (r + 1) / 2 % INF;
		ans += sum * cur % INF;
		key = (key + 1LL * pre * i) % INF;
		ans += key * 1LL * (str[i] - '0') % INF;
		if (pre == 0) pre = 1;
		else pre = pre * 10LL % INF;
		o = o * 10LL % INF;
	}
	printf("%lld\n", ans % INF);
	return 0;
}