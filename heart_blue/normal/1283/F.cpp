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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int deg[N];
int key[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	typedef pair<int, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a[i]);
		deg[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		key[i] = i;
		if (deg[i] == 0)
		{
			pq.emplace(i, i);
		}
	}
	vector<pair<int,int>> ans;
	int pre = 0;
	for (int i = n - 1; i > 0; i--)
	{
		if (pq.empty())
		{
			puts("-1");
			return 0;
		}
		auto [val, x] = pq.top();
		pq.pop();
		int rt = a[i];
		deg[rt] --;
		if (val < pre)
		{
			puts("-1");
			return 0;
		}
		ans.emplace_back(rt, x);
		pre = val;
		key[rt] = max(key[rt], pre);
		if (deg[rt] == 0)
		{
			pq.emplace(key[rt], rt);
		}
	}
	printf("%d\n", a[1]);
	for (auto [a, b] : ans)
		printf("%d %d\n", a, b);
	return 0;
}