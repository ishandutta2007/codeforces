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
const int N = 1e3 + 10;
int a[] = { 2,3,5,7,11,13,17,19,23,29 };
LL p[10][N];
vector<int> v;
LL ans = INF * INF;
inline LL multy(LL a, LL b)
{
	if (a > INF*INF / b) return INF * INF;
	else return a * b;
}
void init()
{
	for (int i = 0; i < 10; i++)
	{
		p[i][0] = 1;
		for (int j = 1; j < N; j++)
		{
			p[i][j] = multy(p[i][j - 1], a[i]);
		}
	}
}
void dfs(int x, int o = 0, LL tot = 1, int cur = 0)
{
	if (x == 1)
	{
		ans = min(ans, tot);
		return;
	}
	if (tot == INF * INF) return;
	for (int i = o; i < v.size(); i++)
	{
		if (x%v[i]) continue;
		dfs(x / v[i], i, multy(tot, p[cur][v[i] - 1]), cur + 1);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = n; i > 1; i--)
	{
		if (n%i == 0) v.push_back(i);
	}
	init();
	dfs(n);
	cout << ans << endl;
	return 0;
}