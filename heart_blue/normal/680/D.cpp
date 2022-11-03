#pragma comment(linker, "/STACK:1024000000,1024000000") 
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
int dp1[N];
LL dp2[N];
LL a[N];
int refrain(LL n)
{
	int l = 1;
	int r = 1e5;
	int ret = 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] > n) r = mid - 1;
		else l = mid + 1, ret = mid;
	}
	return ret;
}
pair<int, LL> dfs(int x, LL tot)
{
	if (tot >= a[x + 1]) tot = a[x + 1] - 1;
	if (a[x] > tot) x = refrain(tot);
	if (tot == a[x + 1] - 1)
	{
		if (dp1[x]) return{ dp1[x],dp2[x] };
	}
	if (x == 1) return{ (int)tot,tot };
	auto p1 = dfs(x - 1, a[x] - 1);
	p1.first += tot / a[x] - 1;
	p1.second += (tot / a[x] - 1)*a[x];
	auto p2 = dfs(x - 1, tot%a[x]);
	p2.first += tot / a[x];
	p2.second += tot / a[x]*a[x];
	int l, r;
	if (p1.first < p2.first) swap(p1, p2);
	if (p1.first == p2.first && p1.second < p2.second) swap(p1, p2);
	if (tot == a[x + 1] - 1) dp1[x] = p1.first, dp2[x] = p1.second;
	return p1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i < N; i++)
	{
		a[i] = LL(i)*i*i;
	}

	MEM(dp1, 0);
	MEM(dp2, 0);
	LL n;
	cin >> n;
	auto p = dfs((int)1e5, n);
	cout << p.first << ' ' << p.second << endl;
	return 0;
}