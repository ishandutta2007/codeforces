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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int x = 0, y = 0;
	int ans = 0;
	int o = 0;
	while (n--)
	{
		int l, r;
		cin >> l >> r;
		int lo = max({ o,x, y });
		int up = min(l, r);
		if (up >= lo)
		{
			ans += up - lo + 1;
			o = up + 1;
		}
		x = l, y = r;
	}
	cout << ans << endl;

	return 0;
}