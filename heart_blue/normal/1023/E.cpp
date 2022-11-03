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
const int N = 5e2 + 10;
int n;
int flag[N][N];
bool check(int r1, int c1, int r2, int c2)
{
	if (r1 > n) return false;
	if (r2 < 1) return false;
	if (flag[r1][c1] || flag[r2][c2]) return false;
	cout << "? " << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
	string str;
	cin >> str;
	return str == "YES";
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x, y;
	string ans = "! ";
	cin >> n;
	x = 1, y = 1;
	int cnt = 0;
	vector<pair<int, int>> vp1, vp2;
	while (x != n || y != n)
	{
		vp1.emplace_back(x, y);
		if (x + y == n + 1) break;
		if (!check(x + 1, y, n, n))
		{
			for (int i = x + 1; i <= n; i++)
				flag[i][y] = 1;
			y++;
		}
		else
		{
			for (int i = y + 1; i <= n; i++)
				flag[x][i] = 1;
			x++;
		}
	}
	auto key = vp1;
	x = n, y = n;
	while (x + y != n + 1)
	{
		key.emplace_back(x, y);
		vp1.pop_back();
		if (vp1.size() == 1) break;
		auto [tx, ty] = vp1.back();
		auto [sx, sy] = vp1[max(0, (int)vp1.size() - 2)];
		if (check(tx, ty, x, y - 1) && check(sx, sy, x, y - 1))
			y--;
		else
			x--;
	}
	sort(key.begin(), key.end());
	for (int i = 0; i + 1 < key.size(); i++)
	{
		if (key[i].first != key[i + 1].first) ans += 'D';
		else ans += 'R';
	}
	cout << ans << endl;
	return 0;
}