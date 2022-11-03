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
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<int, int>> vp;
	priority_queue<tuple<int, int, int>> pq;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		vp.push_back({ x,i });
	}
	sort(vp.begin(), vp.end());
	for (int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		pq.push({ x,0,i });
	}
	int ans1 = 0, ans2 = 0;
	while (!vp.empty() && !pq.empty())
	{
		int x, pos1;
		int y, o, pos2;
		tie(x, pos1) = vp.back();
		tie(y, o, pos2) = pq.top();
		if (x > y)
		{
			vp.pop_back();
			continue;
		}
		if (x < y)
		{
			pq.pop();
			pq.push({ (y + 1) >> 1,o - 1,pos2 });
			continue;
		}
		ans1++;
		ans2 += -o;
		a[pos2] = -o;
		b[pos1] = pos2;
		vp.pop_back();
		pq.pop();
	}
	printf("%d %d\n", ans1, ans2);
	for (int i = 1; i <= m; i++) printf("%d%c", a[i], " \n"[i == m]);
	for (int i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[i == n]);
	return 0;
}