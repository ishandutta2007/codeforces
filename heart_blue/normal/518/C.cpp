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
const int N = 1e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[x] = i;
		b[i] = x;
	}
	LL ans = m;
	while (m--)
	{
		int x;
		cin >> x;
		int px = a[x];
		ans += px / k;
		if (px != 0)
		{
			int py = px - 1;
			int y = b[py];
			a[x] = py;
			a[y] = px;
			b[py] = x;
			b[px] = y;
		}
	}
	cout << ans << endl;

	return 0;
}