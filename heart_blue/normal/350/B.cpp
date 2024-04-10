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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
int nex[N];
int flag[N];
int cnt[N];
int ans[N];
int dfs(int x)
{
	if (x == 0) return 0;
	return 1 + dfs(nex[x]);
}
void output(int x)
{
	if (x == 0) return;
	output(nex[x]);
	printf("%d ", x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> flag[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> nex[i];
		cnt[nex[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (cnt[nex[i]] > 1) nex[i] = 0;
	}
	int maxv = 0;
	int key = -1;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i])
		{
			int o = dfs(i);
			if (o > maxv)
			{
				maxv = o;
				key = i;
			}
		}
	}
	cout << maxv << endl;
	output(key);
	return 0;
}