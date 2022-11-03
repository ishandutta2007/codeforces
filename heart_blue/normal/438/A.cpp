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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
vector<int> v[N];
int energy[N];
int cost[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> cost[i];
	MEM(energy, 0);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		energy[x] += cost[y];
		energy[y] += cost[x];
	}
	int ans = 0;
	while (1)
	{
		int key = -1;
		int maxv = 0;
		for (int i = 1; i <= n; i++)
		{
			if (energy[i] <= 0) continue;
			if (maxv < cost[i])
			{
				maxv = cost[i];
				key = i;
			}
		}
		if (key == -1) break;
		ans += energy[key];
		energy[key] = 0;
		for (auto &x : v[key])
		{
			energy[x] -= cost[key];
		}
	}
	cout << ans << endl;
	return 0;
}