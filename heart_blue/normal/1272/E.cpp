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
int ans[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	MEM(ans, 0x3f);
	int inf = ans[0];
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		for (int o = -1; o <= 1; o += 2)
		{
			int j = i + o * a[i];
			if (j < 1 || j > n) continue;
			v[j].push_back(i);
			if ((a[i] ^ a[j]) & 1)
			{
				ans[i] = 1;
				q.push(i);
			}
		}
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto& y : v[x])
		{
			if (ans[y] > ans[x] + 1)
			{
				ans[y] = ans[x] + 1;
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == inf) ans[i] = -1;
		printf("%d ", ans[i]);
	}
	return 0;
}