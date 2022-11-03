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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
char str[N];
int a[N];
int dp[N][2][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> v(m);
		for (auto& x : v)
			scanf("%d", &x);
		sort(v.begin(), v.end());
		vector<int> key;
		for (int i = 0; i + 1 < v.size(); i++)
		{
			key.push_back(v[i + 1] - v[i] - 1);
		}
		key.push_back(n - v.back() + v.front() - 1);
		sort(key.rbegin(), key.rend());
		while (!key.empty() && key.back() == 0)
			key.pop_back();
		int cur = 0;
		int ans = 0;
		for (auto& x : key)
		{
			if (x - cur <= 0) break;
			int o = max(1, x - cur - 1);
			ans += o;
			if (o == 1) cur += 2;
			else cur += 4;
		}
		printf("%d\n", n - ans);
	}
	return 0;
}