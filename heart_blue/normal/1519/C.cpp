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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int b[N];
LL ans[N];
vector<int> v[N];
LL sum[N];
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
			v[i].clear();
		memset(ans, 0, sizeof(LL) * (n + 1));
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++) v[a[i]].push_back(b[i]);
		for (int i = 1; i <= n; i++)
		{
			sort(v[i].rbegin(), v[i].rend());
			for (int j = 1; j <= v[i].size(); j++)
			{
				sum[j] = sum[j - 1] + v[i][j - 1];
			}
			for (int j = 1; j <= v[i].size(); j++)
			{
				ans[j] += sum[v[i].size() / j * j];
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%lld%c", ans[i], " \n"[i == n]);
	}
	return 0;
}