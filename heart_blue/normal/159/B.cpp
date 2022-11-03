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
const int N = 1e3 + 10;
vector<pair<int, int>> vp;
int a[N][N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vp.resize(n);
	for (auto &p : vp) cin >> p.first >> p.second;
	MEM(a, 0);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		a[x][y]++;
		b[y]++;
	}
	int ans1 = 0, ans2 = 0;
	for (auto &p : vp)
	{
		int x, y;
		tie(x, y) = p;
		if (a[x][y])
		{
			a[x][y]--;
			b[y]--;
			ans2++;
			p = { 0,0 };
		}
	}
	for (auto &p : vp)
	{
		int x, y;
		tie(x, y) = p;
		if (b[y])
		{
			ans1++;
			b[y]--;
		}
	}
	cout << ans1 + ans2 << ' ' << ans2 << endl;
	return 0;
}