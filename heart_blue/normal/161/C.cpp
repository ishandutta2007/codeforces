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
LL ans = 0;
bool isIn(LL o, LL l, LL r)
{
	return l <= o && o <= r;
}
pair<LL, LL> cross(LL l1, LL r1, LL l2, LL r2)
{
	return{ max(l1,l2),min(r1,r2) };
}
void refrain(LL o, LL l, LL r, vector<pair<LL,LL>> &v)
{
	v.push_back(cross(1, o - 1, l, r));
	v.push_back(cross(1, o - 1, l - o, r - o));
}
void check(LL l1, LL r1, LL l2, LL r2, LL o)
{
	if (r1 - l1 + 1 <= ans) return;
	if (r2 - l2 + 1 <= ans) return;
	if (isIn(o, l1, r1) && isIn(o, l2, r2))
	{
		ans = max(ans, min(r1, r2) - max(l1, l2) + 1);
	}
	if (o == 1) return;
	vector<pair<LL,LL>> v1, v2;
	refrain(o, l1, r1, v1);
	refrain(o, l2, r2, v2);
	for (auto &p1 : v1)
	{
		for (auto &p2 : v2)
		{
			check(p1.first, p1.second, p2.first, p2.second, o >> 1);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL l1, l2, r1, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	check(l1, r1, l2, r2, 1 << 30);
	cout << ans << endl;
	return 0;
}