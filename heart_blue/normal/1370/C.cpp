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
const int N = 2e6 + 10;
vector<int> v;
map<int, int> mc;
int check(int n)
{
	if (n == 1) return 0;
	if (n & 1) return 1;
	int &ret = mc[n] = 0;
	for (auto& x : v)
	{
		if (x > n) break;
		if (n % x) continue;
		if (check(n / x) == 0)
		{
			ret = 1;
			return ret;
		}
	}
	ret = check(n - 1) ^ 1;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		v.clear();
		if (n == 1)
		{
			puts("FastestFinger");
			continue;
		}
		if (n & 1)
		{
			puts("Ashishgup");
			continue;
		}
		for (int i = 2; i * i <= n; i++)
		{
			if (n % i) continue;
			if (i & 1) v.push_back(i);
			if ((n / i) & 1) v.push_back(n / i);
		}
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		if (check(n)) puts("Ashishgup");
		else puts("FastestFinger");
	}
	return 0;
}