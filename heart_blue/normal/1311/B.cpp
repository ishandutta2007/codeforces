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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		MEM(flag, 0);
		while (m--)
		{
			int x;
			cin >> x;
			flag[x] = 1;
		}
		for (int o = 1; o <= n; o++)
		{
			for (int i = 1; i < n; i++)
			{
				if (flag[i] && a[i] > a[i + 1])
				{
					swap(a[i], a[i + 1]);
				}
			}
		}
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			if (a[i - 1] > a[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}