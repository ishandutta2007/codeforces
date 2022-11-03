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
const int N = 1e3 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		vp.emplace_back(l, r, i);
	}
	vp.emplace_back(INF, INF, n + 1);
	sort(vp.begin(), vp.end());
	int cur = 0;
	typedef pair<int, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	for (auto& p : vp)
	{
		int l, r, pos;
		tie(l, r, pos) = p;
		while (cur < l)
		{
			if (pq.empty())
			{
				cur = l;
				break;
			}
			ans[pq.top().second] = cur++;
			pq.pop();
		}
		pq.emplace(r, pos);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}