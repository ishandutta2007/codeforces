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
const int N = 7e3 + 10;
int a[2][N];
int flag[2][N];
int cnt[2][N];
int sz[2];
int n;
vector<string> vs = { "Loop","Lose","Win","" };

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	MEM(flag, 0);
	for (int o = 0; o < 2; o++)
	{
		scanf("%d", &sz[o]);
		for (int i = 0; i < sz[o]; i++) scanf("%d", &a[o][i]);
	}
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	q.push({ 1,0 });
	flag[0][0] = flag[1][0] = 1;
	while (!q.empty())
	{
		int o, x;
		tie(o, x) = q.front();
		q.pop();
		for (int i = 0; i < sz[o ^ 1]; i++)
		{
			int y = (x - a[o ^ 1][i] + n) % n;
			if (flag[o ^ 1][y]) continue;
			if (flag[o][x] == 1)
			{
				flag[o ^ 1][y] = 2;
				q.push({ o ^ 1,y });
			}
			else
			{
				cnt[o ^ 1][y]++;
				if (cnt[o ^ 1][y] == sz[o ^ 1])
				{
					flag[o ^ 1][y] = 1;
					q.push({ o ^ 1,y });
				}
			}
		}
	}
	for (int o = 0; o < 2; o++)
	{
		for (int i = 1; i < n; i++)
		{
			printf("%s ", vs[flag[o][i]].c_str());
		}
		puts("");
	}
	return 0;
}