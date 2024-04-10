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
const int N = 1e5 + 10;
int flag[N];
int u[N];
int v[N];
int w[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(flag, 0);
	int n, m, k;
	cin >> n >> m >> k;
	int ans = INF;
	for (int i = 0; i < m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	MEM(flag, 0);
	while (k--)
	{
		int x;
		cin >> x;
		flag[x] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		if (flag[u[i]] ^ flag[v[i]])
		{
			ans = min(ans, w[i]);
		}
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}