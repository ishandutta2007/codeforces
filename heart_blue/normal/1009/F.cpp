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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
vector<int> v[N];
int depth[N];
int ans[N];
class Node
{
public:
	Node(int val = 0, int idx = 0)
	{
		m[abs(idx)] = 1;
		ans = { val,idx };
	}
	void set(int val, int idx)
	{
		ans = { val,idx };
	}
	int size()
	{
		return m.size();
	}
	map<int, int> m;
	pair<int, int> ans;
};
Node* combine(Node *n1, Node *n2)
{
	pair<int, int> maxv = max(n1->ans, n2->ans);
	if (n1->size() < n2->size()) swap(n1, n2);
	for (auto &p : n2->m)
	{
		n1->m[p.first] += p.second;
		maxv = max(maxv, { n1->m[p.first],-p.first });
	}
	n1->set(maxv.first, maxv.second);
	delete n2;
	return n1;
}
Node* dfs(int x, int fa = -1, int d = 1)
{
	depth[x] = d;
	Node *ret = new Node(1,-d);
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		auto tmp = dfs(y, x, d + 1);
		ret = combine(ret, tmp);
	}
	ans[x] = -ret->ans.second - d;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}