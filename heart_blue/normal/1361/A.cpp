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
const int N = 5e5 + 10;
vector<int> v[N];
vector<int> vp[N];
int flag[N];
int cur[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		vp[x].push_back(i);
	}
	vector<int> ans;
	for (int o = 1; o <= n; o++)
	{
		for (auto& x : vp[o])
		{
			ans.push_back(x);
			for (auto& y : v[x])
			{
				flag[cur[y]] = x;
			}
			int key = o + 1;
			for (int i = 1; i <= o; i++)
			{
				if (flag[i] != x)
				{
					key = i;
					break;
				}
			}
			if (key != o)
			{
				puts("-1");
				return 0;
			}
			cur[x] = o;
		}
	}
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}