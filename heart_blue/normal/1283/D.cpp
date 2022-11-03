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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> mc;
	vector<int> v;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		mc[x] = 1;
		v.push_back(x);
	}
	typedef pair<int, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	for (auto& x : v)
	{
		for (int i = -1; i <= 1; i += 2)
		{
			if (mc.count(x + i)) continue;
			pq.emplace(1, x + i);
		}
	}
	v.push_back(INF * 2);
	v.push_back(-INF * 2);
	sort(v.begin(), v.end());
	LL sum = 0;
	vector<int> ans;
	while (ans.size() < m)
	{
		int pos;
		int d;
		tie(d, pos) = pq.top();
		pq.pop();
		if (mc.count(pos)) continue;
		sum += d;
		ans.push_back(pos);
		mc[pos] = 1;
		for (int i = -1; i <= 1; i++)
		{
			int x = pos + i;
			if (mc.count(x)) continue;
			pq.emplace(d + 1, x);
		}
	}
	printf("%lld\n", sum);
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}