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
const int N = 2e5 + 10;
map<pair<int, int>, pair<int, int>> mp;
int a[N], b[N], c[N];
void refrain(int &x, int &y, int &z)
{
	if (x > y) swap(x, y);
	if (y > z) swap(y, z);
	if (x > y) swap(x, y);
}
void check(pair<int, int> &p, int z)
{
	int &x = p.first;
	int &y = p.second;
	if (y < z) swap(y, z);
	if (x < y) swap(x, y);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	pair<int, int> key;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		refrain(a[i], b[i], c[i]);
		check(mp[{a[i], b[i]}], c[i]);
		check(mp[{a[i], c[i]}], b[i]);
		check(mp[{b[i], c[i]}], a[i]);
	}
	for (auto &p : mp)
	{
		int o = min(p.first.first, p.second.first + p.second.second);
		if (ans < o)
		{
			ans = o;
			key = p.first;
		}
	}
	vector<int> v;
	int x, y, z;
	tie(x, y) = key;
	z = mp[key].first;
	refrain(x, y, z);
	for (int i = 1; i <= n; i++)
	{
		if (x == a[i] && y == b[i] && z == c[i])
		{
			v.push_back(i);
			c[i] = -1;
			break;
		}
	}
	tie(x, y) = key;
	z = mp[key].second;
	refrain(x, y, z);
	for (int i = 1; i <= n; i++)
	{
		if (x == a[i] && y == b[i] && z == c[i])
		{
			v.push_back(i);
			break;
		}
	}
	cout << v.size() << endl;
	for (auto &x : v) cout << x << ' ';
	return 0;
}