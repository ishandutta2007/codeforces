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
int a[N][5];
deque<int> q[5];
int sum(int k)
{
	int ret = 0;
	for (int i = 0; i < k; i++)
	{
		if (!q[i].empty()) ret += a[q[i].front()][i];
	}
	return ret;
}
void refrain(vector<int> &v, int k)
{
	for (int i = 0; i < k; i++)
	{
		if (!q[i].empty()) v[i] = a[q[i].front()][i];
		else v[i] = 0;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(m, 0);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int ptr = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			while (!q[j].empty() && q[j].front() < i) q[j].pop_front();
		}
		while (ptr < n)
		{
			for (int j = 0; j < m; j++)
			{
				while (!q[j].empty() && a[q[j].back()][j] <= a[ptr][j]) q[j].pop_back();
				q[j].push_back(ptr);
			}
			ptr++;
			int ret = sum(m);
			if (ret > k) break;
			if (ans < ptr - i)
			{
				ans = ptr - i;
				refrain(v, m);
			}
		}
	}
	for (auto &x : v) cout << x << ' ';
	return 0;
}