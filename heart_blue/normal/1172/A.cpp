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
void check(vector<int>& v1, vector<int>& v2)
{
	priority_queue<int,vector<int>,greater<int>> pq;
	for (auto& x : v1) if (x) pq.push(x);
	deque<int> q(v2.begin(), v2.end());
	int ans = 0;
	while (q.front() != 1)
	{
		ans++;
		if (pq.empty()) return;
		q.push_back(pq.top());
		pq.pop();
		if (q.front())
		{
			pq.push(q.front());
		}
		q.pop_front();
	}
	vector<int> v(q.begin(), q.end());
	if (v.size() != v1.size()) return;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1] >= v[i]) return;
	}
	cout << ans << endl;
	exit(0);
}
int cost[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v1(n), v2(n);
	for (auto& x : v1) cin >> x, cost[x] = 0;
	int cur = 0;
	for (auto& x : v2) cin >> x, cost[x] = ++cur;
	check(v1, v2);
	int maxv = -1;
	for (int i = 1; i <= n; i++)
	{
		maxv = max(maxv, cost[i] - i);
	}
	cout << maxv + 1 + n << endl;
	return 0;
}