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
const int N = 2e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ex, ey, sx, sy;
	int t;
	cin >> t >> sx >> sy >> ex >> ey;
	MEM(a, 0);
	if (ex - sx > 0) a['E'] = ex - sx;
	else a['W'] = sx - ex;
	if (ey - sy > 0) a['N'] = ey - sy;
	else a['S'] = sy - ey;
	LL dis = abs(ex - sx) + abs(ey - sy);
	string str;
	cin >> str;
	str.push_back('#');
	for (int i = 0; i <= t; i++)
	{
		if (dis == 0)
		{
			cout << i << endl;
			return 0;
		}
		if (a[str[i]])
		{
			a[str[i]]--;
			dis--;
		}
	}
	cout << -1 << endl;
	return 0;
}