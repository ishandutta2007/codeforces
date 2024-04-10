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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;

map<LL, LL> ml;
void addWeight(LL x, LL w)
{
	ml[x] += w;
}
LL getWeight(LL x)
{
	if (ml.count(x)) return ml[x];
	else return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	while (q--)
	{
		LL op, u, v, w;
		cin >> op;
		if (op == 1)
		{
			cin >> u >> v >> w;
			while (u != v)
			{
				if (u < v) swap(u, v);
				addWeight(u, w);
				u >>= 1;
			}
		}
		else
		{
			cin >> u >> v;
			LL ans = 0;
			while (u != v)
			{
				if (u < v) swap(u, v);
				ans += getWeight(u);
				u >>= 1;
			}
			cout << ans << endl;
		}
	}
	return 0;
}