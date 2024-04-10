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
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL t, w, b;
	cin >> t >> w >> b;
	LL g = gcd(w, b);
	LL lcm = 1;
	LL minv = min(w, b);
	LL ans;
	if (w / g > t / b)
	{
		ans = min(minv - 1, t);
	}
	else
	{
		lcm = w / g * b;
		ans = min(t%lcm, minv - 1);
		ans += minv*(t / lcm);
	}
	g = gcd(ans, t);
	cout << ans / g << '/' << t / g << endl;
	return 0;
}