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
vector<int> v1[N], v2[N];
int f[N];
int vis[N];
int ans[N];
void dfs1(int x, vector<int> v[N], int cnt = 0)
{
	if (vis[x]) return;
	if (f[x] == 1 && cnt == 1) return;
	if (f[x] == 1) cnt++;
	vis[x] = 1;
	ans[x] |= 1;
	for (auto& y : v[x])
	{
		dfs1(y, v, cnt);
	}
}
void dfs2(int x, vector<int> v[N])
{
	if (vis[x]) return;
	vis[x] = 1;
	ans[x] |= 2;
	if (f[x] == 1) return;
	for (auto& y : v[x])
	{
		dfs2(y, v);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		string str;
		cin >> n >> str;
		int tot = count(str.begin(), str.end(), 'L');
		if (tot == 0 || tot == n)
		{
			printf("%d\n", (n + 2) / 3);
			continue;
		}
		int pos = str.find(str[0] ^ 'L' ^ 'R');
		str = str.substr(pos) + str.substr(0, pos);
		str.push_back('*');
		int cnt = 1;
		int ans = 0;
		for (int i = 1; i < str.length(); i++)
		{
			if (str[i] == str[i - 1]) cnt++;
			else
			{
				ans += cnt / 3;
				cnt = 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}