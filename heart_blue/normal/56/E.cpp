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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int b[N];
struct Node
{
	int x, h, pos;
	void init(int pos)
	{
		this->pos = pos;
		scanf("%d%d", &x, &h);
		h = x + h - 1;
		b[pos] = x;
	}
	bool operator <(const Node &node) const
	{
		return x < node.x;
	}
} a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) a[i].init(i);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	vector<pair<int, int>> vp;
	vp.emplace_back(int(INF), int(INF));
	for(int i = n; i >= 1; i--)
	{
		while (!vp.empty() && a[i].h >= vp.back().first)
		{
			a[i].h = max(a[i].h, vp.back().second);
			vp.pop_back();
		}
		vp.emplace_back(a[i].x, a[i].h);
		ans[a[i].pos] = (upper_bound(b + 1, b + n + 1, a[i].h) - b) - i;
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}