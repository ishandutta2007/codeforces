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
vector<int> v[N];
LL a[N];
pair<LL, LL> dfs(int x, int fa = -1)
{
	LL l = 0, r = 0;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		LL l1, r1;
		tie(l1, r1) = dfs(y, x);
		l = max(l, l1);
		r = max(r, r1);
	}
	if (r - l > a[x]) l += r - l - a[x];
	else r += a[x] - r + l;
	return { l,r };

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	LL l, r;
	tie(l, r) = dfs(1);
	cout << l + r << endl;
	return 0;
}