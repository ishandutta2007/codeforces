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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e3 + 10;
LL a[N][N];
LL b[N];
LL c[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	MEM(b, 0);
	MEM(c, 0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%lld", &a[i][j]);
			b[i + j] += a[i][j];
			c[i - j + 2000] += a[i][j];
		}
	}
	int kx[2], ky[2];
	LL maxv[2];
	MEM(kx, -1);
	MEM(ky, -1);
	MEM(maxv, -1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int o = (i + j) & 1;
			if (maxv[o] < b[i + j] + c[i - j + 2000] - a[i][j])
			{
				maxv[o] = b[i + j] + c[i - j + 2000] - a[i][j];
				kx[o] = i + 1;
				ky[o] = j + 1;
			}
		}
	}
	cout << maxv[0] + maxv[1] << endl;
	cout << kx[0] << ' ' << ky[0] << ' ' << kx[1] << ' ' << ky[1] << endl;
	return 0;
}