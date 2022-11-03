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
int a[N];
char str[N];
bool solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%s", str + 1);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		if (str[i] == 'B')
		{
			if (a[i] < 1) return false;
			vp.emplace_back(1,a[i]);
		}
		else
		{
			if (a[i] > n) return false;
			vp.emplace_back(a[i], n);
		}
	}
	sort(vp.begin(), vp.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	int ptr = 0;
	for (int i = 1; i <= n; i++)
	{
		while (ptr < vp.size() && vp[ptr].first <= i)
		{
			pq.emplace(vp[ptr].second);
			ptr++;
		}
		while (!pq.empty() && pq.top() < i) pq.pop();
		if (pq.empty()) return false;
		pq.pop();
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		if (solve()) puts("YES");
		else puts("NO");
	}
	return 0;
}