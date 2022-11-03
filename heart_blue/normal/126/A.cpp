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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL t1, t2, n, m, t0;
	cin >> t1 >> t2 >> n >> m >> t0;
	if (t1 == t2)
	{
		cout << n << ' ' << m << endl;
		return 0;
	}
	if (t1 == t0)
	{
		cout << n << ' ' << 0 << endl;
		return 0;
	}
	if (t2 == 0)
	{
		cout << 0 << ' ' << m << endl;
		return 0;
	}
	auto refrain = [&](LL& L, LL &R)
	{
		L = abs(L - t0*R);
	};
	auto frain = [&](LL& Y1, LL& Y2, LL Y3, LL Y4)
	{
		LL L1 = Y1*t1 + Y2*t2, R1 = Y1 + Y2;
		LL L2 = Y3*t1 + Y4*t2, R2 = Y3 + Y4;
		if (L1 * R2 > L2 * R1) Y1 = Y3, Y2 = Y4;
		else if (L1 * R2 == L2 * R1)
		{
			if (Y1 + Y2 < Y3 + Y4) Y1 = Y3, Y2 = Y4;
		}
	};
	auto check = [&](LL Y1, LL Y2) -> bool
	{
		LL L1 = Y1*t1 + Y2*t2, R1 = Y1 + Y2;
		return L1 - t0*R1 >= 0;
	};
	LL Y1 = 0, Y2 = m;
	for (int i = 0; i <= n; i++)
	{
		LL l = 0;
		LL r = m;
		LL ky = -1;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			if (check((LL)i, mid)) ky = mid, r = mid - 1;
			else l = mid + 1;
		}
		if (ky != -1)
		{
			frain(Y1, Y2, LL(i), ky);
		}
		
	}
	cout << Y1 << ' ' << Y2 << endl;
	return 0;
}