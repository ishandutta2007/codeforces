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
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	if (k >= min(n, m))
	{
		puts("-1");
		return 0;
	}
	vector<int> v1(n), v2(m);
	for (auto& x : v1)
	{
		cin >> x;
		x += ta;
	}
	for (auto& x : v2)
	{
		cin >> x;
	}
	int ans = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		int rest = k - i;
		if (rest < 0) break;
		int key = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() + rest;
		if (key >= v2.size()) puts("-1"), exit(0);
		ans = max(ans, v2[key] + tb);
	}
	printf("%d\n", ans);
	return 0;
}