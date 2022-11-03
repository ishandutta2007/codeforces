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
const int N = 2e5 + 10;
int a[N];
int b[N];
LL sum[N];
vector<int> solve(int n)
{
	for (int i = 1; i <= n; i++)
	{
		a[i + n] = a[i];
		b[i + n] = b[i];
	}
	deque<int> q;
	vector<int> ret;
	for (int i = 1; i < 2 * n; i++)
	{
		sum[i] = sum[i - 1] + a[i] - b[i];
		while (!q.empty() && i - n >= q.front())
			q.pop_front();
		while (!q.empty() && sum[i] <= sum[q.back()])
			q.pop_back();
		q.push_back(i);
		LL minv = sum[q.front()];
		if (i - n >= 0 && minv - sum[i - n] >= 0)
			ret.push_back(i - n + 1);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	vector<int> ans = solve(n);
	b[0] = b[n];
	for (int i = n; i >= 1; i--)
		b[i] = b[i - 1];
	b[0] = 0;
	reverse(a + 1, a + n + 1);
	reverse(b + 1, b + n + 1);
	vector<int> v = solve(n);
	for (auto& x : v)
	{
		ans.push_back(n - x + 1);
	}
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	return 0;
}