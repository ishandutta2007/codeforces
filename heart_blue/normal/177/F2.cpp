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
const int N = 5e3 + 10;
const int mask = (1 << 5) - 1;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	typedef pair<int, pair<LL, LL>> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	map < pair<LL, LL>, int> vis;
	pq.emplace(0, make_pair(0LL, 0LL));
	priority_queue<int> q;
	q.push(0);
	int n, k, m;
	vector<tuple<int, int, int>> vp;
	cin >> n >> k >> m;
	while (k--)
	{
		int h, w, r;
		cin >> h >> w >> r;
		vp.emplace_back(r, h, w);
	}
	sort(vp.begin(), vp.end());
	int cost = 0;
	while (!pq.empty())
	{
		int val;
		pair<LL, LL> v;
		tie(val, v) = pq.top();
		pq.pop();
		cost++;
		if (cost == m)
		{
			cout << val << endl;
			break;
		}
		LL a, b;
		tie(a, b) = v;
		int flag[41];
		MEM(flag, 0);
		for (int i = 0; i < 60; i += 5)
		{
			int x = a >> i & mask;
			int y = b >> i & mask;
			if (x) flag[n + x] = flag[i / 5 + 1] = 1;
			if (y) flag[n + y] = flag[i / 5 + 13] = 1;
		}
		for (auto& p : vp)
		{
			int w, x, y;
			tie(w, x, y) = p;
			if (flag[x] || flag[y + n]) continue;
			while (q.size() > m) q.pop();
			if (q.size() == m && w + val >= q.top()) break;
			LL A = a, B = b;
			if (x <= 12) A |= LL(y) << ((x - 1) * 5);
			else B |= LL(y) << ((x - 13) * 5);
			if (vis.count({ A,B })) continue;
			vis[make_pair(A, B)] = 1;
			pq.emplace(w + val, make_pair(A, B));
			q.push(w + val);
		}
	}
	return 0;
}