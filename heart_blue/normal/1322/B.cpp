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
const int N = 4e5 + 10;
int a[N];
int solve1(vector<int> v, int maxv)
{
	sort(v.begin(), v.end());
	int n = v.size();
	LL tot = 1LL * n * (n - 1) / 2;
	for (int i = 0; i < v.size(); i++)
	{
		while (v.size() > i + 1 && v.back() + v[i] > maxv)
			v.pop_back();
		tot -= v.size() - i - 1;
	}
	return tot & 1;
}
int solve2(vector<int> v1, vector<int> v2, int maxv)
{
	int n = v1.size();
	int m = v2.size();
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	LL tot = 0;
	for (auto& x : v1)
	{
		while (!v2.empty() && v2.back() + x > maxv)
			v2.pop_back();
		tot += v2.size();
	}
	return tot & 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ans = 0;
	for (int o = 0; o < 28; o++)
	{
		vector<int> v[2];
		int mask = 1 << o;
		mask--;
		for (int i = 1; i <= n; i++)
		{
			v[a[i] >> o & 1].push_back(a[i] & mask);
		}
		int res = solve1(v[0], mask) ^ solve1(v[1], mask) ^ solve2(v[0], v[1], mask);
		ans |= res << o;
	}
	printf("%d\n", ans);
	return 0;
}