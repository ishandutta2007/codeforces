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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int vp, vd, t, f, c;
	cin >> vp >> vd >> t >> f >> c;
	int ans = 0;
	double cur = t;
	if (vd <= vp)
	{
		cout << 0 << endl;
		return 0;
	}
	while (1)
	{
		double cost = vp*cur / (vd - vp);
		if (vp * (cost + cur) > c - (1e-6)) break;
		ans++;
		cur += cost * 2 + f;
	}
	cout << ans << endl;

	return 0;
}