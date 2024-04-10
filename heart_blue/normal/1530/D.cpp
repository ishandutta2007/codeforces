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
const int N = 2e5 + 10;
int flag[N];
int a[N];
int b[N];
int pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		fill(flag, flag + n + 1, 0);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
			if (flag[a[i]]) a[i] = 0;
			else flag[a[i]] = 1;
			pos[a[i]] = i;
		}
		int cur = 1;
		for (int i = 1; i <= n; i++)
		{
			while (flag[cur]) cur++;
			if (a[i] == 0) a[i] = cur++;
			if (a[i] == i)
			{
				swap(a[i], a[pos[b[i]]]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == b[i])
				cnt++;
		}
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", a[i], " \n"[i == n]);
		}
	}
	return 0;
}