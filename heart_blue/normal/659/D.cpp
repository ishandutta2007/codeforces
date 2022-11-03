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
const int N = 3e5 + 10;
LL check(LL ax, LL ay, LL bx, LL by, LL cx, LL cy)
{
	return ax*by + bx*cy + cx*ay - ax*cy - bx*ay - cx*by;
}
LL x[N];
LL y[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	x[n] = x[0], y[n] = y[0];
	x[n + 1] = x[1], y[n + 1] = y[1];
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (check(x[i], y[i], x[i + 1], y[i + 1], x[i + 2], y[i + 2]) > 0) ans++;
	}
	cout << ans << endl;
	return 0;
}