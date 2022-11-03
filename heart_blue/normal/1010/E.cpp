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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<tuple<int, int, int, int>> vp[8];
int flag[N];
int lx, rx, ly, ry, lz, rz;
class BIT
{
public:
	int a[N];
	void init()
	{
		MEM(a, 0x3f);
	}
	inline int lowbit(int x)
	{
		return x & -x;
	}
	void add(int x, int y)
	{
		while (x < N)
		{
			a[x] = min(a[x], y);
			x += lowbit(x);
		}
	}
	int sum(int x)
	{
		int ret = 0x3f3f3f3f;
		while (x)
		{
			ret = min(ret, a[x]);
			x -= lowbit(x);
		}
		return ret;
	}
} B;
int check(int x, int lx, int rx)
{
	if (x < lx) return -1;
	else if (x <= rx) return 0;
	else return 1;
}
void init(int sz, int o = 0)
{
	for (int i = 1; i <= sz; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		int ox = check(x, lx, rx);
		int oy = check(y, ly, ry);
		int oz = check(z, lz, rz);
		if (ox == 0 && oy == 0 && oz == 0)
		{
			if (o == 0)
			{
				puts("INCORRECT");
				exit(0);
			}
			else
			{
				flag[i] = 1;
			}
			continue;
		}
		vector<int> vx, vy, vz;
		if (ox != -1) vx.push_back(1);
		if (ox != 1) vx.push_back(0);
		if (oy != -1) vy.push_back(1);
		if (oy != 1) vy.push_back(0);
		if (oz != -1) vz.push_back(1);
		if (oz != 1) vz.push_back(0);
		if (ox == 0) x = -INF;
		if (oy == 0) y = -INF;
		if (oz == 0) z = -INF;
		if (ox == -1) x = -x;
		if (oy == -1) y = -y;
		if (oz == -1) z = -z;
		for (auto &a : vx)
		{
			for (auto &b : vy)
			{
				for (auto &c : vz)
				{
					vp[a * 4 + b * 2 + c].push_back({ x,y,z,o*i });
				}
			}
		}
	}
}
void solve(vector<tuple<int, int, int, int>> &vp)
{
	if (vp.empty()) return;
	B.init();
	sort(vp.begin(), vp.end());
	vector<int> v;
	for (auto &p : vp)
	{
		int y = get<1>(p);
		v.push_back(y);
	}
	sort(v.begin(), v.end());
	for (auto &p : vp)
	{
		int x, y, z, pos;
		tie(x, y, z, pos) = p;
		int oy = lower_bound(v.begin(), v.end(), y) - v.begin() + 1;
		if (pos == 0)
		{
			B.add(oy, z);
		}
		else
		{
			if (B.sum(oy) <= z)
			{
				flag[pos] = -1;
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int xmax, ymax, zmax;
	int n, m, k;
	cin >> xmax>> ymax>> zmax;
	cin >> n >> m >> k;

	lx = ly = lz = INF;
	rx = ry = rz = 0;
	for (int i = 1; i <= n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		lx = min(lx, x);
		ly = min(ly, y);
		lz = min(lz, z);
		rx = max(rx, x);
		ry = max(ry, y);
		rz = max(rz, z);
	}
	init(m, 0);
	init(k, 1);
	for (int i = 0; i < 8; i++)
		solve(vp[i]);
	puts("CORRECT");
	for (int i = 1; i <= k; i++)
	{
		if (flag[i] == 1) puts("OPEN");
		else if (flag[i] == -1) puts("CLOSED");
		else puts("UNKNOWN");
	}
	return 0;
}