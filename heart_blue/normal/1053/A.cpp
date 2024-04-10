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
const int N = 3e5 + 10;
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m, k;
	cin >> n >> m >> k;
	LL g = gcd(n*m, k);
	if (k / g > 2)
	{
		puts("NO");
		return 0;
	}

	LL g1 = gcd(n, k);
	LL x = n / g1;
	k /= g1;
	LL g2 = gcd(m, k);
	LL y = m / g2;
	k /= g2;
	puts("YES");
	if(k == 1)
	{
		if (x * 2 <= n) x *= 2;
		else y *= 2;
	}
	cout << "0 0" << endl;
	cout << x << ' ' << 0 << endl;
	cout << 0 << ' ' << y << endl;
	return 0;
}