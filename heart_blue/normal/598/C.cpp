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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
class Node
{
public:
	long double x, y;
	int pos;
	long double r;
	Node(long double x = 0, long double y = 0, int pos = 0)
	{
		this->x = x;
		this->y = y;
		this->pos = pos;
		r = atan2(y, x);
	}
	void init(int pos)
	{
		this->pos = pos;
		cin >> x >> y;
		r = atan2(y, x);
	}

	bool operator < (const Node &node) const
	{
		return r < node.r;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<Node> v(n);
	for (int i = 1; i <= n; i++)
	{
		v[i - 1].init(i);
	}
	tuple<long double, int, int> ans = make_tuple(1e18, 0, 0);
	sort(v.begin(), v.end());
	double pi = acos(0.0) * 2;
	for (int i = 0; i < n; i++)
	{
		long double delta = v[(i + 1) % n].r - v[i].r;
		if (delta < 0) delta += 2 * pi;
		delta = min(delta, 2 * pi - delta);
		ans = min(ans, make_tuple(delta, v[i].pos, v[(i + 1) % n].pos));
	}
	long double res;
	int x, y;
	tie(res, x, y) = ans;
	cout << x << ' ' << y << endl;
	return 0;
}