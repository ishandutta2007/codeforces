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
vector<int> v[N];
int a[N];
int flag[N];
void init()
{
	for (int i = 2; i < N; i++)
	{
		if (flag[i]) continue;
		for (int j = i; j < N; j += i)
			flag[j] = i;
	}
}
void build(int x)
{
	while (x > 1)
	{
		int p = flag[x];
		int cnt = 0;
		while (x % p == 0) x /= p, cnt++;
		v[p].push_back(cnt);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		build(x);
	}
	LL ans = 1;
	for (int i = 1; i < N; i++)
	{
		if (v[i].size() + 1 < n) continue;
		while (v[i].size() < n) v[i].push_back(0);
		sort(v[i].begin(), v[i].end());
		int cnt = v[i][1];
		while (cnt--)
			ans *= i;
	}	
	cout << ans << endl;
	return 0;
}