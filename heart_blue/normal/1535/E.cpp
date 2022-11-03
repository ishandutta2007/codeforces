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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int fa[N][20];
int a[N];
int cost[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin >> q >> a[1] >> cost[1];
	for (int i = 2; i <= q + 1; i++)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int p;
			cin >> p >> a[i] >> cost[i];
			fa[i][0] = p + 1;
			for (int o = 0; o + 1 < 20; o++)
			{
				fa[i][o + 1] = fa[fa[i][o]][o];
			}
		}
		else
		{
			int v, w;
			cin >> v >> w;
			v++;
			int tot = 0;
			LL sum = 0;
			while (w > 0)
			{
				int x = v;
				for (int i = 19; i >= 0; i--)
				{
					if (a[fa[x][i]]) x = fa[x][i];
				}
				if (a[x] == 0) break;
				int o = min(w, a[x]);
				tot += o;
				w -= o;
				a[x] -= o;
				sum += 1LL * o * cost[x];
			}
			cout << tot << ' ' << sum << endl;
		}
	}
	return 0;
}