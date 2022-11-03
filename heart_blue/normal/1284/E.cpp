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
LL fact[N];
struct point
{
	LL x, y;
	point(LL x = 0, LL y = 0)
	{
		this->x = x;
		this->y = y;
	}
	point operator -(const point& p)
	{
		return point{ x - p.x,y - p.y };
	}
	LL operator *(const point& p)
	{
		return x * p.y - y * p.x;
	}
};
int Quadrant(point a)
{
	if (a.x > 0 && a.y >= 0)  return 1;
	if (a.x <= 0 && a.y > 0)  return 2;
	if (a.x < 0 && a.y <= 0)  return 3;
	if (a.x >= 0 && a.y < 0)  return 4;
	return 0;
}
bool cmp1(point a, point b)
{
	if (a.x * b.y != a.y * b.x)
		return a.x * b.y > a.y* b.x;
	else return
		a.x < b.x;
}
bool cmp(point a, point b)
{
	if (Quadrant(a) == Quadrant(b))
		return cmp1(a, b);
	else
		return Quadrant(a) < Quadrant(b);
}
LL solve(vector<point>& vp, int key, LL tot)
{
	vector<point> v;
	int n = vp.size();
	for (int i = 0; i < n; i++)
	{
		if (i == key) continue;
		v.push_back(vp[i] - vp[key]);
	}
	sort(v.begin(), v.end(), cmp);
	int sz = v.size();
	for (int i = 0; i < sz; i++)
	{
		v.push_back(v[i]);
	}
	for (int i = 0; i < sz; i++)
	{
		v.push_back(v[i]);
	}
	int ptr = 0;
	for (int i = 0; i < sz * 2; i++)
	{
		ptr = max(ptr, i + 1);
		while (ptr < v.size() && v[i] * v[ptr] > 0) ptr++;
		if (i >= sz) tot -= fact[ptr - i - 1];
	}
	//cout << tot - ret << endl;
	return tot;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i < N; i++)
	{
		fact[i] = 1LL * i * (i - 1) * (i - 2) / 6;
	}
	int n;
	cin >> n;
	vector<point> vp;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		vp.emplace_back(x, y);
	}
	LL ans = 0;
	for (int i = 0; i < n; i++)
		ans += solve(vp, i, 1LL * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24);
	cout << ans << endl;
	return 0;
}