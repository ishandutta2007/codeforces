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
vector<int> v[N];
LL ans[N];
int col[N];
struct Node
{
	map<int, int> m;
	int cnt;
	LL tot;
	Node(int x)
	{
		cnt = 1;
		tot = x;
		m[x] = 1;
	}
};
Node* combine(Node *n1, Node *n2)
{
	if (n1->m.size() < n2->m.size()) swap(n1, n2);
	int &cnt = n1->cnt;
	LL &tot = n1->tot;
	for (auto &p : n2->m)
	{
		n1->m[p.first] += p.second;
		if (cnt < n1->m[p.first]) cnt = n1->m[p.first], tot = 0;
		if (cnt == n1->m[p.first]) tot += p.first;
	}
	delete n2;
	return n1;
}
Node* dfs(int x, int fa = -1)
{
	Node *node = new Node(col[x]);
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		node = combine(node, dfs(y, x));
	}
	ans[x] = node->tot;
	return node;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> col[i];
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}