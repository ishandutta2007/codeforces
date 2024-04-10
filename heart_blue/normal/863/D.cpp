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
tuple<int, int, int> qr[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q, m;
	scanf("%d%d%d", &n, &q, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= q; i++)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		qr[i] = { op,x,y };
	}
	vector<int> ans(m);
	for (auto &x : ans) scanf("%d", &x);
	for (int i = q; i >= 1; i--)
	{
		int op, l, r;
		tie(op, l, r) = qr[i];
		for (auto &x : ans)
		{
			if (x < l || x > r) continue;
			if (op == 1)
			{
				x--;
				if (x < l) x = r;
			}
			else
			{
				x = r - (x - l);
			}
		}
	}
	for (auto &x : ans) printf("%d ", a[x]);
	return 0;
}