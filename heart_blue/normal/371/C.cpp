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
const int N = 5e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int nb, ns, nc;
	int pb, ps, pc;
	LL cb, cs, cc;
	LL tot;
	nb = ns = nc = 0;
	string str;
	cin >> str;
	for (auto &c : str)
	{
		if (c == 'B') nb++;
		if (c == 'S') ns++;
		if (c == 'C') nc++;
	}
	cin >> cb >> cs >> cc;
	cin >> pb >> ps >> pc;
	cin >> tot;
	LL l = 1, r = 2e12;
	LL ans = 0;
	auto check = [&](LL x) ->LL
	{
		return max(0LL, x*nb - cb)*pb + max(0LL, x*nc - cc)*pc + max(0LL, x*ns - cs)*ps;
	};
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		if (check(mid) <= tot) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}