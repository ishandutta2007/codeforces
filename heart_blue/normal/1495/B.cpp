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
int l[N];
int r[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	a[0] = INF;
	a[n + 1] = INF;
	int maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > a[i - 1]) l[i] = l[i - 1] + 1;
		else l[i] = 0;
		maxv = max(maxv, l[i]);
	}
	for (int i = n; i >= 1; i--)
	{
		if (a[i] > a[i + 1]) r[i] = r[i + 1] + 1;
		else r[i] = 0;
		maxv = max(maxv, r[i]);
	}
	vector<int> v1;
	vector<int> v2;
	for (int i = 1; i <= n; i++)
	{
		if (maxv == l[i])
			v1.push_back(i);
		if (maxv == r[i])
			v2.push_back(i);
	}
	if (v1.size() > 1 || v2.size() > 1)
	{
		puts("0");
		return 0;
	}
	if (!v2.empty()) v1.push_back(v2[0]);
	if (v1.size() == 2 && v1[0] == v1[1]) v1.pop_back();
	int ans = 0;
	for (auto& x : v1)
	{
		int a = l[x];
		int b = r[x];
		if (a > b) swap(a, b);
		if (b % 2 == 0) b--;
		if (a > b) ans++;
	}
	printf("%d\n", ans);
	return 0;
}