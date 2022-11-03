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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
int a[N];
LL sum1[N];
LL sum2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	vector<int> v;
	v.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		while (a[i] < a[v.back()]) v.pop_back();
		sum1[i] = sum1[v.back()] + 1LL * (i - v.back()) * a[i];
		v.push_back(i);
	}
	v.clear();
	v.push_back(n + 1);
	for (int i = n; i >= 1; i--)
	{
		while (a[i] < a[v.back()]) v.pop_back();
		sum2[i] = sum2[v.back()] + 1LL * (v.back() - i) * a[i];
		v.push_back(i);
	}
	pair<LL, int> ans = { -1LL,0 };
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, make_pair(sum1[i] + sum2[i] - a[i], i));
	}
	int key = ans.second;
	for (int i = key + 1; i <= n; i++)
	{
		a[i] = min(a[i], a[i - 1]);
	}
	for (int i = key - 1; i >= 1; i--)
	{
		a[i] = min(a[i], a[i + 1]);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}