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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		priority_queue<pair<int, int>> pq;
		int n;
		cin >> n;
		pq.emplace(n, -n);
		int cur = 1;
		while (!pq.empty())
		{
			int len, r;
			tie(len, r) = pq.top();
			pq.pop();
			r = -r;
			int l = r - len + 1;
			int mid = (l + r) / 2;
			a[mid] = cur++;
			if (l < mid) pq.emplace(mid - l, -(mid - 1));
			if (mid < r) pq.emplace(r - mid, -r);
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", a[i], " \n"[i == n]);
		}
	}
	return 0;
}