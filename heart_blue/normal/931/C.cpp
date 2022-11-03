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
const int N = 5e3 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, int> mc;
	for (auto &x : v)
	{
		cin >> x;
		mc[x]++;
	}
	sort(v.begin(), v.end());
	if (v.back() - v.front() < 2)
	{
		cout << n << endl;
		for (auto &x : v) cout << x << ' ';
		return 0;
	}
	int a, b, c;
	a = mc[v.front()];
	c = mc[v.back()];
	b = n - a - c;
	int x = a + b / 2, z = c + b / 2, y = b % 2;
	tuple<int, int, int> ans = { INF,0,0 };
	for (; x >= 0 && z >= 0; y += 2, x--, z--)
	{
		ans = min(ans, { min(x,a) + min(y,b) + min(z,c),x,y });
	}
	int res;
	tie(res, x, y) = ans;
	z = n - x - y;
	cout << res << endl;
	while (x--) cout << v.front() << ' ';
	while (y--) cout << v.front() + 1 << ' ';
	while (z--) cout << v.back() << ' ';
	return 0;
}