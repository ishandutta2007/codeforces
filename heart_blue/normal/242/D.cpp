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
const int N = 1e5 + 10;
vector<int> v[N];
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> cnt[i];
		if (cnt[i] == 0) q.push(i);
	}
	vector<int> ans;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cnt[x]--;
		ans.push_back(x);
		for (auto &y : v[x])
		{
			cnt[y]--;
			if (cnt[y] == 0) q.push(y);
		}
	}
	printf("%d\n", ans.size());
	for (auto &x : ans) printf("%d ", x);
	return 0;
}