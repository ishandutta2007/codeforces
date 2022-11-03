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
const int N = 1e6 + 10;
vector<int> v[N];
int a[N];
int cnt[N];
void init()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
		{
			v[j].push_back(i);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	init();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] >= N) continue;
		cnt[a[i]]++;
	}
	pair<int, int> ans = { 0,-1 };
	for (int i = 1; i <= m; i++)
	{
		int tot = 0;
		for (auto &x : v[i])
		{
			tot += cnt[x];
		}
		ans = max(ans, { tot,-i });
	}
	printf("%d %d\n", -ans.second, ans.first);
	int x = -ans.second;
	for (int i = 1; i <= n; i++)
	{
		if (x%a[i]) continue;
		printf("%d ", i);
	}
	return 0;
}