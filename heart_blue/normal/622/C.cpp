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
const int N = 1e6 + 10;
vector<int> v[N];
int a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	MEM(ans, 0);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = n; i > 0; i--)
	{
		v[a[i]].push_back(i);
	}
	ans[n + 1] = n + 1;
	for (int i = 1; i < N; i++)
	{
		int m = v[i].size();
		if (m > 0)
		{
			int pre = n + 1;
			for (auto &x : v[i])
			{
				if (pre - x == 1) ans[x] = ans[pre];
				else ans[x] = x + 1;
				pre = x;
			}
		}
	}
	while (q--)
	{
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		if (a[l] != x) printf("%d\n", l);
		else if (ans[l] > r) puts("-1");
		else printf("%d\n", ans[l]);
	}

	return 0;
}