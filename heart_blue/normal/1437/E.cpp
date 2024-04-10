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
const int N = 5e5 + 10;
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	vector<int> v;
	v.push_back(0);
	while (m--)
	{
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	v.push_back(n + 1);
	int ans = 0;
	a[0] = -INF;
	a[n + 1] = 2 * INF;
	for (int i = 0; i + 1 < v.size(); i++)
	{
		int l = v[i];
		int r = v[i + 1];
		if (r - l > a[r] - a[l])
		{
			puts("-1");
			return 0;
		}
		vector<LL> key;
		for (int j = l + 1; j < r; j++)
		{
			if (j - l > a[j] - a[l] || r - j > a[r] - a[j]) continue;
			LL x = a[j] - j;
			auto iter = upper_bound(key.begin(), key.end(), x);
			if (iter == key.end()) key.push_back(x);
			else *iter = x;
		}
		ans += r - l - 1 - key.size();
	}
	printf("%d\n", ans);
	return 0;
}