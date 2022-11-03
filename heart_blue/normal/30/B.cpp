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
const int N = 3e2 + 10;
int day[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},
				{0,31,29,31,30,31,30,31,31,30,31,30,31} };

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	int d1, m1, y1;
	int d2, m2, y2;
	scanf("%d.%d.%d", &d1, &m1, &y1);
	scanf("%d.%d.%d", &d2, &m2, &y2);
	v.push_back(d2);
	v.push_back(m2);
	v.push_back(y2);
	sort(v.begin(), v.end());
	do
	{
		d2 = v[0], m2 = v[1], y2 = v[2];
		int o = y2 % 4 == 0;
		if (m2 < 1 || m2 > 12) continue;
		if (d2 < 1 || d2 > day[o][m2]) continue;
		if (y1 - y2 < 18) continue;
		if (y1 - y2 > 18) puts("YES"), exit(0);
		if (m1 > m2) puts("YES"), exit(0);
		if (d1 >= d2) puts("YES"), exit(0);

	} while (next_permutation(v.begin(), v.end()));
	puts("NO");
	return 0;
}