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
int w[N];
int deg[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &w[i]);
		LL ans = 0;
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			ans += w[x] + w[y];
			deg[x]++;
			deg[y]++;
		}
		vector<LL> v;
		v.push_back(ans);
		vector<int> key;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < deg[i]; j++)
				key.push_back(w[i]);
			deg[i] = 0;
		}
		sort(key.begin(), key.end());
		for (auto& x : key)
		{
			ans -= x;
			v.push_back(ans);
		}
		reverse(v.begin(), v.end());
		for (auto& x : v)
			printf("%lld ", x);
		puts("");
	}
	return 0;
}