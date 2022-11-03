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
const int N = 1e6 + 10;
int flag[N];
LL powmod(LL a, int b, int mod = INF)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int p, k;
	cin >> p >> k;
	if (k == 0)
	{
		cout << powmod(p, p - 1) << endl;
		return 0;
	}
	else if (k == 1)
	{
		cout << powmod(p, p) << endl;
		return 0;
	}
	MEM(flag, 0);
	int cnt = 0;
	for (int i = 1; i < p; i++)
	{
		if (flag[i]) continue;
		cnt++;
		int o = i;
		while (!flag[o])
		{
			flag[o] = 1;
			o = 1LL * o*k%p;
		}
	}
	cout << powmod(p, cnt) << endl;
	return 0;
}