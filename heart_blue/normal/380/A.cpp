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
LL a[N];
class Node
{
public:
	LL l, r;
	int len;
	Node(LL l, LL r, int len)
	{
		this->l = l;
		this->r = r;
		this->len = len;
	}
	LL getans(LL x)
	{
		if (x < l || x > r) return 0LL;
		return a[(x - l) % len + 1];
	}
};
map<LL, LL> ms;
vector<Node> v;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL q, n, m;
	cin >> q;
	m = 1e5;
	LL k = 1;
	LL op, x, y;
	while (q--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> x;
			if (k > m) ms[k++] = x;
			else a[k++] = x;
		}
		else
		{
			cin >> x >> y;
			LL l = k;
			LL r = k + x*y - 1;
			k = r + 1;
			int o = 1;
			for (LL i = l; i <= min(r, m); i++)
			{
				a[i] = a[o++];
				if (o > x) o = 1;
			}
			if (r > m) v.push_back(Node(l, r, x));
		}
	}
	cin >> n;
	int p = 0;
	while (n--)
	{
		cin >> x;
		if (x <= m)
		{
			cout << a[x] << ' ';
			continue;
		}
		if (ms.count(x))
		{
			cout << ms[x] << ' ';
			continue;
		}
		while (!v[p].getans(x)) p++;
		cout << v[p].getans(x) << ' ';
	}
	return 0;
}