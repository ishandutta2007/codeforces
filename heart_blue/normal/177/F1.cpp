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
int a[N];
int pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	typedef pair<int, vector<pair<int, int>>> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	map<vector<pair<int, int>>, int> vis;
	pq.emplace(0, vector<pair<int, int>>());
	int n, k, m;
	vector<tuple<int, int, int>> vp;
	cin >> n >> k >> m;
	while (k--)
	{
		int h, w, r;
		cin >> h >> w >> r;
		vp.emplace_back(h, w + n, r);
	}
	while (!pq.empty())
	{
		int val;
		vector<pair<int, int>> v;
		tie(val, v) = pq.top();
		pq.pop();
		m--;
		if (m == 0)
		{
			cout << val << endl;
			break;
		}
		int flag[41];
		MEM(flag, 0);
		for (auto& p : v)
			flag[p.first] = flag[p.second] = 1;
		for (auto& p : vp)
		{
			int x, y, w;
			tie(x, y, w) = p;
			if (flag[x] || flag[y]) continue;
			auto tmp = v;
			tmp.emplace_back(x, y);
			sort(tmp.begin(), tmp.end());
			if (vis.count(tmp)) continue;
			vis[tmp] = 1;
			pq.emplace(w + val, tmp);
		}
	}
	return 0;
}