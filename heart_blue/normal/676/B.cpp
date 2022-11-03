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
const double eps = 1e-10;
const LL N = 1e3 + 20;
double a[N][N];
int main()
{
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <  N; j++)
		{
			a[i][j] = 0;
		}
	}
	a[1][1] = t;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[i][j] - 1 > eps)
			{
				a[i + 1][j] += (a[i][j] - 1) / 2;
				a[i + 1][j + 1] += (a[i][j] - 1) / 2;
				a[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (abs(a[i][j] - 1) < eps)
			{
				ans++;
			}
		}
		
	}
	cout << ans << endl;
	return 0;
}