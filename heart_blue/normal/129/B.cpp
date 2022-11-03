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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int a[N][N];
int deg[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	MEM(a, 0);
	MEM(deg, 0);
	cin >> n >> m;
	int x, y;
	while (m--)
	{
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
		deg[x]++, deg[y]++;
	}
	int ans = 0;
	while (1)
	{
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] == 1) v.push_back(i);
		}
		if (v.empty()) break;
		ans++;
		for (auto &x : v)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[x][i])
				{
					a[x][i] = a[i][x] = 0;
					deg[x]--;
					deg[i]--;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}