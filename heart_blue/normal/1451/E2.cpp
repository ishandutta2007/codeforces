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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int ask(int i, int j, string str)
{
	cout << str << ' ' << i << ' ' << j << endl;
	int ret;
	cin >> ret;
	return ret;
}
int a[N];
int pre[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int mask = n - 1;
	int x = 1;
	int y = -1;
	MEM(pre, -1);
	pre[0] = 1;
	int kx = -1;
	int ky = -1;

	for (int i = 2; i <= n; i++)
	{
		a[i] = ask(1, i, "XOR");
		if (a[i] == mask)
			y = i;
		if (pre[a[i]] != -1)
		{
			kx = i;
			ky = pre[a[i]];
		}
		pre[a[i]] = i;
	}
	if (kx == -1)
	{
		int z = 2;
		if (z == y) z++;
		int sumxy = n - 1;
		int sumyz = ask(y, z, "AND") * 2 + (a[y] ^ a[z]);
		int sumxz = ask(x, z, "AND") * 2 + (a[x] ^ a[z]);
		int sum = (sumxy + sumyz + sumxz) / 2;
		a[1] = sum - sumyz;
	}
	else
	{
		int val = ask(kx, ky, "AND");
		a[1] = val ^ a[kx];
	}
	for (int i = 2; i <= n; i++)
		a[i] ^= a[1];
	cout << "!";
	for (int i = 1; i <= n; i++)
	{
		cout << ' ' << a[i];
	}
	cout << endl;

	return 0;
}