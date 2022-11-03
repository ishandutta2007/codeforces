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
const int N = 1e3 + 10;
LL mul(LL x, LL y)
{
	if (x >= LLONG_MAX / y) return LLONG_MAX;
	else return x*y;
}
/*
10000000000000000 9999999999999999 1
10000000000000000 1 1

*/
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL w, m, k;
	cin >> w >> m >> k;
	LL o = 1;
	int cnt = 0;
	while (o <= m) o *= 10, cnt++;
	LL ans = 0;
	while (1)
	{
		if (mul(k*cnt, o - m) > w)
		{
			ans += w / (k*cnt);
			break;
		}
		w -= mul(k*cnt, o - m);
		ans += (o - m);
		cnt++;
		m = o;
		o *= 10;
	}
	cout << ans << endl;
	return 0;
}