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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		vector<pair<int, int>> v;
		if (x >= i)
		{
			int j = i;
			v.emplace_back(x - i + 1, -1);
			v.emplace_back(n - x, 1);
			v.emplace_back(i, -1);
		}
		else
		{
			v.emplace_back(n - i + 1, 1);
			v.emplace_back(x, -1);
			v.emplace_back(i - x, 1);
		}
		int cur = 0;
		int last = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j].first == 0) continue;
			int pos = cur + i;
			while (pos > n) pos -= n;
			a[cur] += abs(pos - x) - last;
			a[cur + 1] -= abs(pos - x) - last;
			a[cur + 1] += v[j].second;
			a[cur + v[j].first] -= v[j].second;
			cur += v[j].first - 1;
			int np = cur + i;
			while (np > n) np -= n;
			last = abs(np - x);
			cur++;
		}
	}
	LL sum = 0;
	LL delta = 0;
	int key = 0;
	LL ans = a[0];
	for (int i = 0; i < n; i++)
	{
		delta += a[i];
		sum += delta;
		if (ans > sum)
		{
			ans = sum;
			key = i;
		}
	}
	printf("%lld %d\n", ans, key);
	return 0;
}