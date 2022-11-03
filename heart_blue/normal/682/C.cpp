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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
vector<pair<int, int>> v[N];
int cnt = 0;
int dfs(int x, LL dist = 0, int fa = -1)
{
	int cur = cnt++;
	int sum = 0;
	for (auto &p : v[x])
	{
		int y, w;
		tie(y, w) = p;
		if (y == fa) continue;
		sum += dfs(y, max((LL)w, dist + w), x);
	}
	if (dist > a[x]) return cnt - cur;
	else return sum;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++)
	{
		int y, w;
		cin >> y >> w;
		v[i].push_back({ y,w });
		v[y].push_back({ i,w });
	}
	cout << dfs(1) << endl;
	return 0;
}