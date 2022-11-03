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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int ans[N];
int flag[N];
#define b(i,j) a[(i)*m+(j)]
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(ans, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b(i, j);
		}
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i + 1 < n; i++)
		{
			flag[i + 1] = i + 1;
			if (b(i, j) <= b(i + 1, j))
			{
				flag[i + 1]++;
			}
		}
		flag[n] = n;
		for (int i = n - 1; i > 0; i--)
		{
			if (flag[i] != i && flag[i + 1] != i + 1)
			{
				flag[i] = flag[i + 1];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			ans[i] = max(ans[i], flag[i]);
		}

	}
	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		if (ans[l] >= r) puts("Yes");
		else puts("No");
	}
	return 0;
}