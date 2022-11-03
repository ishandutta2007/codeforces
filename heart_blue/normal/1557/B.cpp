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
const int N = 1e5 + 10;
int flag[N];
void refrain(vector<int>& v)
{
	vector<int> key = v;
	sort(key.begin(), key.end());
	for (auto& x : v)
	{
		x = lower_bound(key.begin(), key.end(), x) - key.begin() + 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		memset(flag, 0, sizeof(int) * (n + 1));
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		refrain(v);
		int ans = 0;
		int pre = -INF;
		for (auto& x : v)
		{
			if (pre + 1 != x) ans++;
			pre = x;
		}
		if (ans > k) puts("No");
		else puts("Yes");
	}
	return 0;
}