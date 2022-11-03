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
const int N = 5E5 + 10;
LL x[N];
LL y[N];
char c[N];
LL minv[N];
int key[N];
int dx[] = { 1,1,0,-1,-1,-1,0,1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
int sig(LL a)
{
	if (a == 0) return 0;
	if (a > 0) return 1;
	else return -1;
}
int getdir(LL a, LL b)
{
	if (a != 0 && b != 0 && abs(a) != abs(b)) return -1;
	a = sig(a);
	b = sig(b);
	for (int i = 0; i < 8; i++)
	{
		if (a == dx[i] && b == dy[i]) return i;
	}
	return -1;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i] >> x[i] >> y[i];
		x[i] -= a;
		y[i] -= b;
	}
	MEM(key, -1);
	MEM(minv, 0x1f);
	for (int i = 0; i < n; i++)
	{
		int o = getdir(x[i], y[i]);
		if (o == -1) continue;
		LL d = abs(x[i]) + abs(y[i]);
		if (d < minv[o]) minv[o] = d, key[o] = i;
	}
	for (int i = 0; i < 8; i++)
	{
		if (key[i] == -1) continue;
		if (i & 1)
		{
			int o = key[i];
			if (c[o] == 'B' || c[o] == 'Q')
			{
				cout << "YES" << endl;
				return 0;
			}
		}
		else
		{
			int o = key[i];
			if (c[o] == 'R' || c[o] == 'Q')
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}