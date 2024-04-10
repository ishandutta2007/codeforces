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
const int N = 5e2 + 10;
vector<int> v[N];
int kx = 0, ky = 0;
int vis[N];
int in[N];
vector<int> s;
vector<int> q;
int ok = 0;
void dfs(int x)
{
	if (vis[x])
	{
		if (in[x])
		{
			ok = 1;
			q.clear();
			q.push_back(x);
			while (1)
			{
				int y = s.back();
				s.pop_back();
				q.push_back(y);
				if (y == x) break;
			}
			reverse(q.begin(), q.end());
			ok = 1;
		}
		return;
	}
	s.push_back(x);
	vis[x] = in[x] = 1;
	for (auto &y : v[x])
	{
		if (x == kx && y == ky) continue;
		dfs(y);
		if (ok) return;
	}
	s.pop_back();
	in[x] = 0;
}
bool check(int n, int x = 0, int y = 0)
{
	ok = 0;
	MEM(vis, 0);
	MEM(in, 0);
	s.clear();
	q.clear();
	kx = x, ky = y;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		dfs(i);
		if (ok) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	if (check(n))
	{
		puts("YES");
		return 0;
	}
	vector<int> key = q;
	for (int i = 1; i < key.size(); i++)
	{
		if (check(n, key[i - 1], key[i]))
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}