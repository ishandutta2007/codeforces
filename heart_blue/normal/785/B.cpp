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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int lmax1, rmin1;
	int lmax2, rmin2;
	lmax1 = lmax2 = 0;
	rmin1 = rmin2 = INF;
	int ans = 0;
	int n;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		lmax1 = max(lmax1, x);
		rmin1 = min(rmin1, y);
	}
	int m;
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		lmax2 = max(lmax2, x);
		rmin2 = min(rmin2, y);
	}
	ans = max(ans, max(lmax1 - rmin2, lmax2 - rmin1));
	cout << ans << endl;
	return 0;
}