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
const int N = 2e2 + 10;
struct Node
{
public:
	int l, r;
	int pos;
	bool operator < (Node &node)
	{
		if (l / 1000 != node.l / 1000) return l / 1000 < node.l / 1000;
		else
		{
			if (l / 1000 % 2 == 0) return r < node.r;
			else return r > node.r;
		}
	}
};
bool solve(vector<Node> &vp)
{
	for (auto &node : vp)
	{
		swap(node.l, node.r);
	}
	sort(vp.begin(), vp.end());
	LL inf = 2.5e9;
	LL tot = 0;
	for (int i = 1; i < vp.size(); i++)
	{
		tot += abs(vp[i].l - vp[i - 1].l) + abs(vp[i].r - vp[i - 1].r);
	}
	if (tot > inf) return false;
	for (auto &p : vp) printf("%d\n", p.pos);
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<Node> vp(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &vp[i].l, &vp[i].r);
		vp[i].pos = i + 1;
	}
	if (solve(vp) || solve(vp)) return 0;
	return 0;
}