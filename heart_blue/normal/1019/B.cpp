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
const int N = 2e5 + 10;
int ask(int l, int r)
{
	int x, y;
	cout << "? " << l << endl;
	cin >> x;
	cout << "? " << r << endl;
	cin >> y;
	return x - y;
}
inline int sgn(int x)
{
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int key = ask(1, n / 2 + 1);
	if (abs(key) & 1)
	{
		cout << "! " << -1 << endl;
		return 0;
	}
	if (key == 0)
	{
		cout << "! " << 1 << endl;
	}
	int l = 1, r = n / 2;
	int ret = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int res = ask(mid, mid + n / 2);
		if (res == 0)
		{
			ret = mid;
			break;
		}
		if (sgn(res) == sgn(key)) l = mid + 1;
		else r = mid - 1;
	}
	cout << "! " << ret << endl;
	return 0;
}