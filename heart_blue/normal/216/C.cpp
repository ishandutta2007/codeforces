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
int sz[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	queue<int> q;
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> ans;
	for (int i = 1; i <= k; i++) q.push(1);
	for (int i = 1; i <= k; i++) ans.push_back(1);
	for (int i = 1; i <= n + m; i++)
	{
		while (sz[i])
		{
			sz[i]--;
			q.push(i);
		}
		while (q.size() < k)
		{
			q.push(i);
			ans.push_back(i);
		}
		while (!q.empty() && q.front() + n - 1 == i)
		{
			sz[q.front() + n + m]++;
			q.pop();
		}
		if (q.empty())
		{
			ans.push_back(i);
			q.push(i);
		}
	}
	printf("%d\n", ans.size());
	for (auto& x : ans) printf("%d ", x);
	return 0;
}