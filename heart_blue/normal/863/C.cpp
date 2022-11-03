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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e3 + 10;
int A[4][4];
int B[4][4];
int flag[4][4];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	int a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> B[i][j];
		}
	}
	LL ans1 = 0, ans2 = 0;
	LL o = 1;
	int x = a, y = b;
	int r = 0;
	int t = 0;
	while (1)
	{
		if (flag[x][y])
		{
			r = o - flag[x][y];
			t = flag[x][y];
			break;
		}
		flag[x][y] = o++;
		tie(x, y) = make_pair(A[x][y], B[x][y]);
	}
	t = min(t * 1LL, n);
	n -= t;
	while (t--)
	{
		if ((a - b + 3) % 3 == 1) ans1++;
		if ((b - a + 3) % 3 == 1) ans2++;
		tie(a, b) = make_pair(A[a][b], B[a][b]);
	}
	o = n % r;
	while (o--)
	{
		if ((a - b + 3) % 3 == 1) ans1++;
		if ((b - a + 3) % 3 == 1) ans2++;
		tie(a, b) = make_pair(A[a][b], B[a][b]);
	}
	LL tot1 = 0, tot2 = 0;
	LL d = n / r;
	while (r--)
	{
		if ((a - b + 3) % 3 == 1) tot1++;
		if ((b - a + 3) % 3 == 1) tot2++;
		tie(a, b) = make_pair(A[a][b], B[a][b]);
	}
	printf("%lld %lld\n", ans1 + tot1 * d, ans2 + tot2 * d);
	return 0;
}