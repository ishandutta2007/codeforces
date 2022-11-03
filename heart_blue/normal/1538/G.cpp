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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;

string rebuild(string str)
{
	if (str.length() > 9) return str.substr(0, 4) + "*" + str.substr(str.length() - 4);
	else return str;
}
int getans(const string str)
{
	int ans = 0;
	for (int i = 0; i + 4 <= str.length(); i++)
	{
		if (str.substr(i, 4) == "haha")
			ans++;
	}
	return ans;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		LL x, y, a, b;
		scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
		if (x > y) swap(x, y);
		if (a > b) swap(a, b);
		LL minv = 0;
		if (x != y && a != b)
		{
			minv = min({ x / a,y / b, (y - x) / (b - a) });
		}
		x -= minv * a;
		y -= minv * b;
		LL ans = minv;
		LL o = min(x, y) / (a + b);
		ans += o * 2;
		x -= (a + b) * o;
		y -= (a + b) * o;
		if (x >= a && y >= b) ans++;
		else if (x >= b && y >= a) ans++;
		printf("%lld\n", ans);
	}
	return 0;
}