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
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
const int M = 60*720;
int flag[M+10];
bool check(int l, int r)
{
	for (int i = l; ; i++)
	{
		if (i == M) i = 0;
		if (flag[i]) break;
		if (i == r) 
			return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	MEM(flag, 0);
	if (h == 12) h = 0;
	// 1/120 1/10 6
	flag[h*3600+m*60+s] = 1;
	flag[(m*60+s)*12] = 1;
	flag[s*720] = 1;
	if (t1 == 12) t1 = 0;
	if (t2 == 12) t2 = 0;
	t1 *= 3600;
	t2 *= 3600;
	if (check(t1, t2) || check(t2, t1)) puts("YES");
	else puts("NO");
	return 0;
}