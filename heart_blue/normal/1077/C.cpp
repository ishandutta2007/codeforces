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
LL lmax[N];
LL rmax[N];
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL sum = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum += a[i];
	for (int i = 1; i <= n; i++) lmax[i] = max(a[i], lmax[i - 1]);
	for (int i = n; i >= 1; i--) rmax[i] = max(a[i], rmax[i + 1]);
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		LL maxv = max(lmax[i - 1], rmax[i + 1]);
		if (maxv * 2 == sum - a[i])
		{
			ans.push_back(i);
		}
	}
	printf("%d\n", ans.size());
	for (auto &x : ans) printf("%d ", x);
	return 0;
}