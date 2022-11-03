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
const int N = 1e6 + 10;
int nex[N];
int flag1[N];
int flag2[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(nex, 0);
	MEM(flag1, 0);
	MEM(flag2, 0);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		flag1[x]++;
		flag2[y]++;
		if (x == 0)
		{
			ans[1] = y;
			continue;
		}
		if (y == 0)
		{
			ans[n - 2] = x;
			continue;
		}
		nex[x] = y;
	}
	for (int i = 0; i < N; i++)
	{
		if (flag1[i] + flag2[i] == 1)
		{
			if (flag1[i])
			{
				ans[0] = i;
			}
			else
			{
				ans[n - 1] = i;
			}
		}
	}
	for (int i = 0; i + 2 < n; i++)
	{
		ans[i+2] = nex[ans[i]];
	}
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
	return 0;
}