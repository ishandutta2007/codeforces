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
vector<LL> check(vector<LL>& v, LL o)
{
	if (v.empty()) return v;
	vector<LL> v1, v2;
	for (auto& x : v)
	{
		if ((x / o) & 1) v1.push_back(x);
		else v2.push_back(x);
	}
	v2 = check(v2, o * 2);
	if (v1.size() > v2.size()) return v1;
	else return v2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<LL> v;
	vector<LL> ans;
	for (int i = 1; i <= n; i++)
	{
		LL x;
		cin >> x;
		v.push_back(x);
	}
	ans = check(v, 1);
	map<LL, int> mc;
	for (auto& x : ans) mc[x]++;
	printf("%d\n", n - ans.size());
	for (auto& x : v)
	{
		if (mc.count(x))
		{
			if (mc[x]-- == 1)
				mc.erase(x);
			continue;
		}
		printf("%lld ", x);
	}
	return 0;
}