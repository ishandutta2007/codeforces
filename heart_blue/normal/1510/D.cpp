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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> v[10];
vector<int> key, res;
double maxv[10][10];
int cnt[10][10];
int n, d;
double flag[20][20];
void dfs(int id, int cur, double pro = 0)
{
	if (flag[id][cur] >= pro) return;
	flag[id][cur] = pro;
	if (id == 10)
	{
		if (cur != d) return;
		vector<int> ans;
		for (int i = 0; i < key.size(); i++)
		{
			for (int j = 0; j < key[i]; j++)
				ans.push_back(v[i][j]);
		}
		res = ans;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (cnt[id][i] == -1) continue;
		key[id] = cnt[id][i];
		dfs(id + 1, cur * i % 10, pro + maxv[id][i]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		v[x % 10].push_back(x);
	}
	for (int i = 0; i < 10; i++)
	{
		fill(flag[i], flag[i] + 10, -1.0);
		sort(v[i].rbegin(), v[i].rend());
		fill(maxv[i], maxv[i] + 10, -1.0);
		MEM(cnt[i], -1);
		maxv[i][1] = 0;
		cnt[i][1] = 0;
		int cur = 1;
		double sum = 0;
		for (int j = 0; j < v[i].size(); j++)
		{
			cur = cur * i % 10;
			sum += log(v[i][j]);
			maxv[i][cur] = sum;
			cnt[i][cur] = j + 1;
		}
	}
	key.resize(10, 0);
	fill(flag[10], flag[10] + 10, -1.0);
	dfs(0, 1);
	if (res.empty()) puts("-1");
	else
	{
		printf("%d\n", res.size());
		for (auto& x : res)
			printf("%d ", x);
	}
	return 0;
}