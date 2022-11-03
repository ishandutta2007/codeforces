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
const int N = 1e5 + 10;
int n, m;
int l[N];
int r[N];
int ans[N];

bool check(int l1, int r1, int l2, int r2)
{
	if (r1 - l1 < r2 - l2) swap(l1, l2), swap(r1, r2);
	if (r2 <= l1 || l2 >= r1) return false;
	if (l1 <= l2 && r2 <= r1) return false;
	return true;
}
bool solve(int s)
{
	if (ans[s] != -1) return true;
	queue<int> q;
	q.push(s);
	ans[s] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1; i <= m; i++)
		{
			if (i == x) continue;
			if (check(l[x], r[x], l[i], r[i]))
			{
				if (ans[i] == -1)
				{
					ans[i] = ans[x] ^ 1;
					q.push(i);
				}
				else
				{
					if (ans[i] == ans[x]) 
						return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(ans, -1);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> l[i] >> r[i];
		if (l[i] > r[i]) swap(l[i], r[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		if (!solve(i))
		{
			puts("Impossible");
			return 0;
		}
	}
	for (int i = 1; i <= m; i++) putchar("io"[ans[i]]);
	return 0;
}