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
const int N = 2e2 + 10;
vector<pair<int, int>> vp;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		vp.push_back({ x,y });
		v.push_back(x);
		v.push_back(y);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (auto &p : vp)
	{
		int x, y;
		tie(x, y) = p;
		x = lower_bound(v.begin(), v.end(), x) - v.begin();
		y = lower_bound(v.begin(), v.end(), y) - v.begin();
		a[x][y] = a[y][x] = 1;
	}
	n = v.size();
	for (int i = 0; i < n; i++)
	{
		vector<int> ans;
		int tot = 0;
		for (int j = 0; j < n; j++) tot += a[i][j];
		for (int j = 0; j < n; j++)
		{
			if (i == j || a[i][j]) continue;
			int cnt = 0;
			for (int k = 0; k < n; k++)
			{
				if (a[i][k] && a[k][j]) cnt++;
			}
			if (cnt * 100 >= tot * k) ans.push_back(v[j]);
		}
		printf("%d: %d", v[i], ans.size());
		for (auto &x : ans) printf(" %d", x);
		puts("");
	}
	return 0;
}