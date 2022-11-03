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
const int N = 1e6 + 10;
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	int n, r;
	LL low;
	cin >> n >> r >> low;
	low *= n;
	LL sum = 0;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		a[y] += r - x;
		sum += x;
	}
	LL rest = low - sum;
	if (rest < 0) rest = 0;
	LL ans = 0;
	for (int i = 1; i < N; i++)
	{
		LL minv = min(rest, a[i]);
		ans += minv*LL(i);
		rest -= minv;
	}
	cout << ans << endl;
	return 0;
}